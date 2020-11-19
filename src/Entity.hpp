#pragma once

#include <SFML/System/Vector2.hpp>

/**
 * I'm going for an inheritance based approach instead of an entity component
 * system. But why?!? Entity component systems are always better!
 *
 * Well, our game is dead simple. The only moving parts are ships and
 * bullets. The ships are basically identical. We'll have no problem
 * maintaining a simple inheritance tree:
 *
 *           ------Entity------
 *          /        |         \
 *       Ship      Bullet   Black Hole
 *      /    \
 *   Enemy   Player
 *
 * If we were going to start adding new ship types, or have upgrades
 * to the ships, different bullets, bosses, etc, etc, then an ECS would make
 * sense. Therefore, this game doesn't scale well, but that's ok - it isn't
 * meant to. We're trading rapid development time for scalability. In the
 * interest of actually finishing, we'll go with the easy route.
 */

class Entity
{
public:
    void setVelocity(const sf::Vector2f &velocity);
    void setVelocity(const float vx, const float vy);

    const sf::Vector2f &getVelocity() const;

private:
    sf::Vector2f mVelocity;
};
