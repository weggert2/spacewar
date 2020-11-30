/**
 * @file
 *
 * $Id: MovementSystem.cpp $
 * @author Bill Eggert
 */

#include "MovementSystem.hpp"

#include "Game.hpp"

#include "components/Enemy.hpp"
#include "components/Position.hpp"
#include "components/Projectile.hpp"
#include "components/Motion.hpp"

#include "entity_utils.hpp"
#include "math_utils.hpp"

#include <algorithm>

void MovementSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    (void)events;
    const float dtf = (float)dt;

    Position::Handle position;
    Motion::Handle motion;
    for (entityx::Entity e : entities.entities_with_components(motion, position))
    {
        (void)e;
        position->rotate(motion->getOmega()*dtf);

        const sf::Vector2f n = computeHeading(position->getTheta());
        position->move(motion->getSpeed()*n*dtf);

        /* Wrap around for things that aren't projectiles. */
        if (!e.has_component<Projectile>())
        {
            position->setPos(wrap(position->getPos()));
        }
    }
}

sf::Vector2f MovementSystem::wrap(
    const sf::Vector2f &pos) const
{
    const auto wrapImpl = [](float coord, float limit) {
        if (coord < 0.0f)  return limit;
        if (coord > limit) return 0.0f;
        return coord;
    };

    return sf::Vector2f(
        wrapImpl(pos.x, Game::ScreenWidth),
        wrapImpl(pos.y, Game::ScreenHeight));
}
