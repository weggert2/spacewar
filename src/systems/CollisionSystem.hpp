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
};
