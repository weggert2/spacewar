#pragma once

#include <entityx/System.h>

class Movement : public entityx::System<Movement>
{
public:
    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);
};
