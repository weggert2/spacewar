#pragma once

#include <SFML/System/Vector2.hpp>

/* Windows compatibility */
#define _USE_MATH_DEFINES
#include <math.h>


/**
 * SFML uses degrees, cmath uses radians. This converts.
 */
inline float toRad(const float deg)
{
    static constexpr float PI_F = static_cast<float>(M_PI);
    return deg*PI_F/180.0f;
}

/**
 * Returns the distance (squared) between two points.
 */
inline float distsq(
    const sf::Vector2f &a,
    const sf::Vector2f &b)
{
    const float dx = a.x-b.x;
    const float dy = a.y-b.y;

    return dx*dx + dy*dy;
}
