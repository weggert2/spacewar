/**
 * @file
 *
 * $Id: EnemyControlSystem.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <entityx/System.h>
#include <SFML/System/Vector2.hpp>

class Motion;
class Position;
class Weapon;

class EnemyControlSystem : public entityx::System<EnemyControlSystem>
{
public:
    EnemyControlSystem() = default;

    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);

private:
    void pursuePlayer(
        Motion &motion,
        Weapon &weapon,
        const Position &position,
        const sf::Vector2f &playerPos) const;
};
