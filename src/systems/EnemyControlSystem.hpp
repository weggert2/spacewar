/**
 * @file
 *
 * $Id: EnemyControlSystem.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <entityx/System.h>

class EnemyControlSystem : public entityx::System<EnemyControlSystem>
{
public:
    EnemyControlSystem() = default;

    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);
};
