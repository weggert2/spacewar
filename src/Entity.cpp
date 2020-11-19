#include "Entity.hpp"

void Entity::setVelocity(
    const sf::Vector2f &velocity)
{
    mVelocity = velocity;
}

void Entity::setVelocity(
    const float vx,
    const float vy)
{
    mVelocity.x = vx;
    mVelocity.y = vy;
}

const sf::Vector2f &getVelocity() const
{
    return mVelocity;
}
