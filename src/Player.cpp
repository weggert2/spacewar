#include "Player.hpp"

#include <iostream>

/** Hard code the textyre path. Not amazing, but it'll get us going. */
const std::string Player::texturePath = "../assets/textures/blue/ship.png";


Player::Player():
    mBody(),
    mImpulseUp(false),
    mImpulseLeft(false),
    mImpulseDown(false),
    mImpulseRight(false)
{
    if (!mTexture.loadFromFile(texturePath))
    {
        std::cerr << "Couldn't load texture: " << texturePath;
        /* TODO: What to do here? Some default shape? */
    }

    mBody.setTexture(mTexture);
    mBody.setScale(0.4, 0.4);
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
    /* For now, we'll do constant movement.
     * TODO: Add momentum, which requires a "force" balance and then
     * a velocity update. */

    sf::Vector2f vel(0.0, 0.0);
    if (mImpulseUp)    vel.y -= playerSpeed;
    if (mImpulseDown)  vel.y += playerSpeed;
    if (mImpulseLeft)  vel.x -= playerSpeed;
    if (mImpulseRight) vel.x += playerSpeed;

    mBody.move(vel*deltaTime.asSeconds());
}

sf::Sprite &Player::get()
{
    return mBody;
}
