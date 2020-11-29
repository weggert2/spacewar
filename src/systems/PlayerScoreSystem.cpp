/**
 * @file
 *
 * $Id: PlayerScoreSystem.cpp $
 * @author Bill Eggert
 */

#include "PlayerScoreSystem.hpp"

#include <nlohmann/json.hpp>

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <set>
#include <sstream>

PlayerScoreSystem::PlayerScoreSystem(
    entityx::EventManager &eventManager):
        mEventManager(eventManager),
        mShouldUpdate(false),
        mScore(0.0),
        mScoreStr()
{
    eventManager.subscribe<LoseGameEvent>(*this);
    eventManager.subscribe<WinGameEvent>(*this);
    eventManager.subscribe<StartGameEvent>(*this);
    eventManager.subscribe<EnemyDestroyedEvent>(*this);
    eventManager.subscribe<PauseGameEvent>(*this);
    eventManager.subscribe<ResumeGameEvent>(*this);
}

void PlayerScoreSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    (void)entities;
    (void)events;

    if (mShouldUpdate)
    {
        mScore = std::max(mScore-(float)dt, 0.0f);
    }
}

const std::wstring &PlayerScoreSystem::getScores() const
{
    return mScoreStr;
}

void PlayerScoreSystem::receive(
    const LoseGameEvent &event)
{
    (void)event;
    mShouldUpdate = false;
    updateHighScores();
}

void PlayerScoreSystem::receive(
    const WinGameEvent &event)
{
    (void)event;
    mShouldUpdate = false;
    updateHighScores();
}

void PlayerScoreSystem::receive(
    const StartGameEvent &event)
{
    (void)event;
    mShouldUpdate = true;
    mScore = 0.0;
}

void PlayerScoreSystem::receive(
    const EnemyDestroyedEvent &event)
{
    mScore += event.getPointValue();
}

void PlayerScoreSystem::receive(
    const PauseGameEvent &event)
{
    (void)event;
    mShouldUpdate = false;
}

void PlayerScoreSystem::receive(
    const ResumeGameEvent &event)
{
    (void)event;
    mShouldUpdate = true;
}

/* Store the scores next to the binary. */
static const std::string fname = "scores.json";

void PlayerScoreSystem::updateHighScores()
{
    /* Read any existing scores. */
    nlohmann::json j;
    std::ifstream ifs(fname);
    if (ifs)
    {
        ifs >> j;
    }

    /* convert from json -> STL container. */
    auto &node = j["scores"];
    using set_t = std::set<float, std::greater<float>>;
    set_t scores;
    if (!node.empty())
    {
        scores = node.get<set_t>();
    }

    /* Insert the current score. */
    scores.insert(mScore);

    /* Keep only the 10 highest scores. */
    while (scores.size() > mMaxNumScores)
    {
        auto it = scores.end();
        it--;
        scores.erase(it);
    }

    /* Write the updates scores to file. */
    node = nlohmann::json(scores);
    std::ofstream ofs(fname);
    ofs << j;

    /* Pretty print to the string so we can display on screen. This needs
     * to be done since we need to manage the lifetime of the string. */
    std::wstringstream wss;
    wss << L"High Scores:\n";
    size_t i = 1;
    for (const float score : scores)
    {
        wss << L"   " << i << L":     " << (int)score << L"\n";
        i++;
    }

    for (; i <= mMaxNumScores; ++i)
    {
        wss << L"   " << i << L":     0\n";
    }

    mScoreStr = wss.str();
}
