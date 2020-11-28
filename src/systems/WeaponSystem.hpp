#pragma once

#include <entityx/System.h>

class WeaponSystem : public entityx::System<WeaponSystem>
{
public:
    WeaponSystem() = default;

    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);
};
