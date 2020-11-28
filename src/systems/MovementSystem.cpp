#include "MovementSystem.hpp"

#include "components/Position.hpp"
#include "components/Motion.hpp"

#include "math_utils.hpp"

#include <cmath>

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
    }
}
