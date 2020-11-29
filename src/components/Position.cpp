/**
 * @file
 *
 * $Id: Position.cpp $
 * @author Bill Eggert
 */

#include "Position.hpp"

Position::Position(
    const sf::Vector2f &position,
    const float rotation,
    const sf::Vector2f &offset):
        mX(position),
        mTheta(rotation),
        mOffset(offset)
{
}

const sf::Vector2f &Position::getPos() const
{
    return mX;
}

const sf::Vector2f &Position::getOffset() const
{
    return mOffset;
}

float Position::getTheta() const
{
    return mTheta;
}

void Position::move(
    const sf::Vector2f &dx)
{
    mX += dx;
}

void Position::setX(
    const sf::Vector2f &x)
{
    mX = x;
}

void Position::rotate(
    const float dTheta)
{
    mTheta += dTheta;
}

void Position::setTheta(
    const float theta)
{
    mTheta = theta;
}
