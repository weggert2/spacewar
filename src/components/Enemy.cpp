#include "Enemy.hpp"

Enemy::Enemy(
    const EnemyType type,
    const size_t pointValue):
        mType(type),
        mPointValue(pointValue)
{
}

size_t Enemy::getPointValue() const
{
    return mPointValue;
}
