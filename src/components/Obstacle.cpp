#include "Obstacle.hpp"

Obstacle::Obstacle(
    const ObstacleType type):
        mType(type)
{
}

ObstacleType Obstacle::getType() const
{
    return mType;
}
