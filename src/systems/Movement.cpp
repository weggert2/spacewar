#include "Movement.hpp"

void Movement::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    double dt)
{
    Position::Handle position;
    Motion::Handle motion;

    for (Entity e : entities.entities_with_components(motion, position))
    {
        (void)e;

        position.rotate(motion.getOmega()*dt);

        /* Rotate the y unit vector by theta to get the heading direction. */
        const float theta = position.getTheta();
        const sf::Vector2f n(-std::sin(theta), std::cos(theta));
        position.move(motion.getSpeed()*n*dt);
    }
}
