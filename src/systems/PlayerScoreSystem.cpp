#include "PlayerScoreSystem.hpp"

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
        mScore -= dt;
    }
}

float PlayerScoreSystem::getScore() const
{
    return mScore;
}

void PlayerScoreSystem::receive(
    const LoseGameEvent &event)
{
    mShouldUpdate = false;
    mEventManager.emit<UpdateHighScoreEvent>(mScore);
}

void PlayerScoreSystem::receive(
    const WinGameEvent &event)
{
    mShouldUpdate = false;
    mEventManager.emit<UpdateHighScoreEvent>(mScore);
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
