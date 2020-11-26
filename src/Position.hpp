#pragma once

#include <entityx/Entity.h>
#include <SFML/System/Vector2.hpp>

class Position : public entityx::Component<Position>
{
public:
    Position(
        const sf::Vector2f &position,
        const double rotation);

    const sf::Vector2f &getPos() const;
    double getRot() const;

private:
    /* Position and rotation. */
    sf::Vector2f mX;
    double mTheta;
};
