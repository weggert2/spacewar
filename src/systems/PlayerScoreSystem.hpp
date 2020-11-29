#pragma once

#include "Events.hpp"

#include <entityx/Entity.h>
#include <entityx/System.h>

class PlayerScoreSystem : public entityx::System<PlayerScoreSystem>,
                          public entityx::Receiver<PlayerScoreSystem>
{
public:
    explicit PlayerScoreSystem(
        entityx::EventManager &eventManager);

    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);

    float getScore() const;

    void receive(const LoseGameEvent &event);
    void receive(const WinGameEvent &event);
    void receive(const StartGameEvent &event);
    void receive(const EnemyDestroyedEvent &event);

private:
    entityx::EventManager &mEventManager;
    bool mShouldUpdate;
    float mScore;
};
