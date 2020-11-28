#pragma once

#include <entityx/System.h>

class PlayerDeathSystem : public entityx::System<PlayerDeathSystem>
{
public:
    PlayerDeathSystem() = default;

    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);
};
