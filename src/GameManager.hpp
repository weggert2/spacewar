#pragma once

#include "Events.hpp"

#include <entityx/Event.h>
#include <entityx/Entity.h>

enum class GameState
{
    start_menu,
    playing,
    paused,
    game_over,
};

/**
 * The state stack
 */

class GameManager : public entityx::Receiver<GameManager>
{
public:
    GameManager(
        entityx::EntityManager &entityManager,
        entityx::EventManager &eventManager);

    void receive(const LaunchGameEvent &launch);
    // void receive(const StartGameEvent &start);
    // void receive(const QuitGameEvent &quit);
    // void receive(const PauseGameEvent &pause);
    // void receive(const ResumeGameEvent &resume);

private:
    void subscribeEvents();

private:
   entityx::EntityManager& mEntityManager;
   entityx::EventManager& mEventManager;
   GameState mGameState;
};
