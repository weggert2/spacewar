/**
 * @file
 *
 * $Id: Obstacle.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <entityx/Entity.h>

enum class ObstacleType
{
    BlackHole,
};

class Obstacle : public entityx::Component<Obstacle>
{
public:
    explicit Obstacle(
        const ObstacleType type);

    ObstacleType getType() const;

private:
    ObstacleType mType;
};
