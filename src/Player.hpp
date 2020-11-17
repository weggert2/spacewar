#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();

    const sf::CircleShape &get() const;
    sf::CircleShape &get();

private:
    /* We'll make this a sprite at some point. */
    sf::CircleShape mBody;
};
