#include "PlayerScoreSystem.hpp"

#include <algorithm>
#include <cmath>

PlayerScoreSystem::PlayerScoreSystem(
    entityx::EventManager &eventManager):
        mEventManager(eventManager),
        mShouldUpdate(false),
        mScore(0.0)
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

void PlayerScoreSystem::updateHighScores()
{

}
