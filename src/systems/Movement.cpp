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
        position = motion.getTheta();


//     const float dt = deltaTime.asSeconds();
//     const float dTheta = omega*dt;
//     mBody.rotate(dTheta);

//     /* Rotate the unit y vector by theta to get the heading direction. */
//     const float theta = toRad(mBody.getRotation());
//     const sf::Vector2f n(-std::sin(theta), std::cos(theta));
//     mBody.move(velocity*n*dt);
    }
}
