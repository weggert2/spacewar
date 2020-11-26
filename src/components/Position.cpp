#include "Position.hpp"

Position::Position(
    const sf::Vector2f &position,
    const double rotation):
        mX(position),
        mTheta(rotation)
{
}

const sf::Vector2f &Position::getX() const
{
    return mX;
}

double Position::getTheta() const
{
    return mTheta;
}
