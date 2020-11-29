/**
 * @file
 *
 * $Id: Position.hpp $
 * @author Bill Eggert
 */

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
        const float rotation,
        const sf::Vector2f &offset = sf::Vector2f(80.0, -50.0));

    const sf::Vector2f &getPos() const;
    const sf::Vector2f &getOffset() const;
    float getTheta() const;

    void move(const sf::Vector2f &dx);
    void setPos(const sf::Vector2f &x);

    void rotate(const float dTheta);
    void setTheta(const float theta);

private:
    /* Position and rotation. */
    sf::Vector2f mX;
    float mTheta;
    const sf::Vector2f mOffset;
};
