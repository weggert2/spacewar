#pragma once

#include <cmath>

/**
 * SFML uses degrees, cmath uses radians. This converts.
 */
inline float toRad(const float deg)
{
    return deg*M_PI/180.0;
}
