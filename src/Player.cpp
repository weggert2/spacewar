#include "Player.hpp"

#include <iostream>

Player::Player():
    mBody()
{
    mBody.setRadius(40.f);
    mBody.setPosition(100.f, 100.f);
    mBody.setFillColor(sf::Color::Cyan);
}

const sf::CircleShape &Player::get() const
{
    return mBody;
}

sf::CircleShape &Player::get()
{
    return mBody;
}
