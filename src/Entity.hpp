#pragma once

#include <SFML/System/Vector2.hpp>

class Entity
{
public:
    void setVelocity(const sf::Vector2f &velocity);
    void setVelocity(const float vx, const float vy);

    const sf::Vector2f &getVelocity() const;

private:
    sf::Vector2f mVelocity;
};
