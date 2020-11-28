#include "Movement.hpp"

#include "components/Position.hpp"
#include "components/Motion.hpp"

#include "math_utils.hpp"

#include <cmath>

void Movement::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    Position::Handle position;
    Motion::Handle motion;

    for (entityx::Entity e : entities.entities_with_components(motion, position))
    {
        (void)e;

        const float dtf = (float)dt;
        position->rotate(motion->getOmega()*dtf);

        /* Rotate the y unit vector by theta to get the heading direction. */
        const float theta = toRad(position->getTheta());
        const sf::Vector2f n(-std::sin(theta), std::cos(theta));
        position->move(motion->getSpeed()*n*dtf);
    }
}
