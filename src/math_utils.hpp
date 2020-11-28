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

/**
 * Returns the heading given the rotational angle, assuming degrees.
 */
inline sf::Vector2f computeHeading(const float theta)
{
    const float th = toRad(theta);
    return sf::Vector2f(-std::sin(th), std::cos(th));
}
