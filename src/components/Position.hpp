#pragma once

#include <entityx/Entity.h>
#include <SFML/System/Vector2.hpp>

class Position : public entityx::Component<Position>
{
public:
    /* The offset is a hack so that projectiles can be placed at the
     * center of ships. TODO: remove the ugly hack. */
    Position(
        const sf::Vector2f &position,
        const double rotation,
        const sf::Vector2f &offset = sf::Vector2f(80.0, -50.0));

    const sf::Vector2f &getX() const;
    const sf::Vector2f &getOffset() const;
    double getTheta() const;

    void move(const sf::Vector2f &dx);
    void setX(const sf::Vector2f &x);

    void rotate(const double dTheta);
    void setTheta(const double theta);

private:
    /* Position and rotation. */
    sf::Vector2f mX;
    double mTheta;
    const sf::Vector2f mOffset;
};
