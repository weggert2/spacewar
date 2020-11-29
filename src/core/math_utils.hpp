/**
 * @file
 *
 * $Id: meth_utils.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <SFML/System/Vector2.hpp>

/* Windows compatibility */
#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>

struct Circle
{
    Circle(
        const sf::Vector2f &p_,
        const float r_):
            p(p_),
            r(r_)
    {
    }

    sf::Vector2f p;
    float r;
};


/**
 * SFML uses degrees, cmath uses radians. This converts.
 */
inline float toRad(const float deg)
{
    static constexpr float fac = static_cast<float>(M_PI)/180.0f;
    return deg*fac;
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
 * Rotate a vector by an angle theta, assuming degrees.
 */
inline sf::Vector2f rotate(
    const sf::Vector2f &v,
    const float theta)
{
    const float th = toRad(theta);

    const float x1 = v.x;
    const float y1 = v.y;

    const float c = std::cos(th);
    const float s = std::sin(th);

    const float x2 = x1*c - y1*s;
    const float y2 = x1*s + y1*c;

    return sf::Vector2f(x2,y2);
}

/**
 * Returns the heading given the rotational angle, assuming degrees.
 */
inline sf::Vector2f computeHeading(const float theta)
{
    return rotate(sf::Vector2f(0.0, 1.0), theta);
}

inline void printRect(
    const sf::FloatRect &r)
{
    std::cout << r.left << ", " << r.top << ", "
              << r.width << ", " << r.height << std::endl;
}

/**
 * Dumb detection for whether a circle intersects an axis-aligned rectangle.
 */
inline bool intersects(
    const sf::FloatRect &rect,
    const Circle &circle)
{
    const float r = circle.r;
    const float cx = circle.p.x;
    const float cy = circle.p.y;

    const auto circleContains = [&](float x, float y) {
        const float dx = cx - x;
        const float dy = cy - y;
        return dx*dx + dy*dy < r*r;
    };

    return circleContains(rect.left,              rect.top)                ||
           circleContains(rect.left + rect.width, rect.top)                ||
           circleContains(rect.left,              rect.top + rect.height)  ||
           circleContains(rect.left + rect.width, rect.top + rect.height);
}
