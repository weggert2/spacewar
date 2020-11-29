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
        mScore = std::max(mScore-dt, 0.0);
    }
}

void PlayerScoreSystem::receive(
    const LoseGameEvent &event)
{
    mShouldUpdate = false;
    updateHighScores();
}

void PlayerScoreSystem::receive(
    const WinGameEvent &event)
{
    mShouldUpdate = false;
    updateHighScores();
}

void PlayerScoreSystem::receive(
    const StartGameEvent &event)
{
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
    mShouldUpdate = false;
}

void PlayerScoreSystem::receive(
    const ResumeGameEvent &event)
{
    mShouldUpdate = true;
}

/* Store the scores next to the binary. */
static const std::string    fname = "scores.json";

void PlayerScoreSystem::updateHighScores()
{
    /* Read any existing scores. */
    nlohmann::json j;
    std::ifstream ifs(fname);
    if (ifs)
    {
        ifs >> j;
    }

    using set_t = std::set<float, std::greater<float>>;
    set_t scores;

    auto &node = j["scores"];
    if (!node.empty())
    {
        scores = node.get<set_t>();
    }

    /* Insert the current score. */
    scores.insert(mScore);

    /* Keep only the 10 highest scores. */
    while (scores.size() > 10.0)
    {
        auto it = scores.end();
        it--;
        scores.erase(it);
    }

    /* Write to file. */
    node = nlohmann::json(scores);
    std::ofstream ofs(fname);
    ofs << j;

    /* Pretty print to the string so we can display on screen. */
    std::wstringstream wss;

    if (scores.empty())
    {
        wss << L"No high scores yet!";
    }
    else
    {
        size_t i = 1;
        for (const float score : scores)
        {
            wss << i << L": " << std::setprecision(2) << score << L"\n";
            i++;
        }
    }

    mScoreStr = wss.str();
}
