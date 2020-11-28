#include "Position.hpp"

Position::Position(
    const sf::Vector2f &position,
    const double rotation,
    const sf::Vector2f &offset):
        mX(position),
        mTheta(rotation),
        mOffset(offset)
{
}

const sf::Vector2f &Position::getX() const
{
    return mX;
}

const sf::Vector2f &Position::getOffset() const
{
    return mOffset;
}

double Position::getTheta() const
{
    return mTheta;
}

void Position::move(
    const sf::Vector2f &dx)
{
    mX += dx;
}

void Position::setX(
    const sf::Vector2f x)
{
    mX = x;
}

void Position::rotate(
    const double dTheta)
{
    mTheta += dTheta;
}

void Position::setTheta(
    const double theta)
{
    mTheta = theta;
}
