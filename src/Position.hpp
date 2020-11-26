#pragma once

#include <entityx/Entity.h>
#include <SFML/System/Vector2.hpp>

class Position : public entityx::Component<Position>
{
public:
    Position(
        const sf::Vector2f &position,
        const double rotation);

private:
    /* Position and rotation. */
    sf::Vector2f mX;
    double mTheta;
};