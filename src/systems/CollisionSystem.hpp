#pragma once

#include "Events.hpp"

#include <entityx/Entity.h>
#include <entityx/System.h>

class CollisionSystem : public entityx::System<CollisionSystem>,
                        public entityx::Receiver<CollisionSystem>
{
public:
    explicit CollisionSystem(
        entityx::EventManager &eventManager);

    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);

    void receive(const LoseGameEvent &event);

private:
    /*
     * We can get away with implementing this in the cpp since the
     * CollisionSystem is the only thing that will ever use it.
     */
    template <typename T, typename U>
    void detectCollisions(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt,
        const float hitbox1Fac = 0.45,
        const float hitbox2Fac = 1.0);

private:
    entityx::EventManager &mEventManager;
};