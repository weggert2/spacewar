#pragma once

#include <entityx/Entity.h>
#include <entityx/System.h>

class CollisionSystem : public entityx::System<CollisionSystem>
{
public:
    CollisionSystem() = default;

    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);
};
