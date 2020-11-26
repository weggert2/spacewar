#pragma once

#include <entityx/Entity.h>

enum class ObstacleType
{
    black_hole,
    unknown,
};

class Obstacle : public entityx::Component<Obstacle>
{
public:
    explicit Obstacle(
        const ObstacleType type = ObstacleType::black_hole);

    ObstacleType getType() const;

private:
    ObstacleType mType;
}
