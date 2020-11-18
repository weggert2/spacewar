#include "Player.hpp"

#include <iostream>

Player::Player():
    mBody(),
    mImpulseUp(false),
    mImpulseLeft(false),
    mImpulseDown(false),
    mImpulseRight(false)
{
    mBody.setRadius(40.f);
    mBody.setPosition(100.f, 100.f);
    mBody.setFillColor(sf::Color::Cyan);
}

void Player::setImpulseUp(
    const bool choice)
{
    mImpulseUp = choice;
}

void Player::setImpulseLeft(
    const bool choice)
{
    mImpulseLeft = choice;
}

void Player::setImpulseDown(
    const bool choice)
{
    mImpulseDown = choice;
}

void Player::setImpulseRight(
    const bool choice)
{
    mImpulseRight = choice;
}

void Player::update(
    const sf::Time &deltaTime)
{
    sf::Vector2f vel(0.0, 0.0);
    if (mImpulseUp)    vel.y -= playerSpeed;
    if (mImpulseDown)  vel.y += playerSpeed;
    if (mImpulseLeft)  vel.x -= playerSpeed;
    if (mImpulseRight) vel.x += playerSpeed;

    mBody.move(vel*deltaTime.asSeconds());
}

sf::CircleShape &Player::get()
{
    return mBody;
}
