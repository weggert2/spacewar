/**
 * @file
 *
 * $Id: Enemy.cpp $
 * @author Bill Eggert
 */

#include "Enemy.hpp"

Enemy::Enemy(
    const EnemyType type,
    const float pointValue):
        mType(type),
        mPointValue(pointValue)
{
}

float Enemy::getPointValue() const
{
    return mPointValue;
}
