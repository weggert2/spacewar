#pragma once

#include <entityx/System.h>

class MovementSystem : public entityx::System<MovementSystem>
{
public:
    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);
};
