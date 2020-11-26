#pragma once

#include <entityx/Entity.h>
#include <SFML/System/Vector2.hpp>

class Position : public entityx::Component<Position>
{
public:
    Position(
        const sf::Vector2f &position,
        const double rotation);

    const sf::Vector2f &getX() const;
    double getTheta() const;

    void move(const sf::Vector2f &dx);
    void setX(const sf::Vector2f x);

    void rotate(const double dTheta);
    void setTheta(const double theta);

private:
    /* Position and rotation. */
    sf::Vector2f mX;
    double mTheta;
};
