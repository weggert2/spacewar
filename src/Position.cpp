#include "Position.hpp"

Position::Position(
    const sf::Vector2f &position,
    const double rotation):
        mX(position),
        mTheta(rotation)
{
}
