#include "Position.hpp"

Position::Position(
    const sf::Vector2f &position,
    const double rotation):
        mX(position),
        mTheta(rotation)
{
}

const sf::Vector2f &Position::getPos() const
{
    return mX;
}

double Position::getRot() const
{
    return mTheta;
}
