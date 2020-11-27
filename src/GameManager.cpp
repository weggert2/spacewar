#include "GameManager.hpp"

#include <iostream>

GameManager::GameManager(
    entityx::EntityManager &entityManager,
    entityx::EventManager &eventManager):
        mEntityManager(entityManager),
        mEventManager(eventManager),
        mGameState(GameState::start_menu)
{
    subscribeEvents();
}

void GameManager::subscribeEvents()
{
    mEventManager.subscribe<LaunchGameEvent>(*this);
    // mEventManager.subscribe<StartGameEvent>(*this);
    // mEventManager.subscribe<QuitGameEvent>(*this);
    // mEventManager.subscribe<PauseGameEvent>(*this);
    // mEventManager.subscribe<ResumeGameEvent>(*this);
}

void GameManager::receive(
    const LaunchGameEvent &launch)
{
    std::cout << "Game launched!\n";
}
