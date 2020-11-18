#pragma once

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
