#include "Player.hpp"

#include <iostream>

/** Hard code the textyre path. Not amazing, but it'll get us going. */
const std::string Player::texturePath = "../assets/textures/blue/ship.png";


Player::Player():
    mBody(),
    mImpulseUp(false),
    mImpulseDown(false),
    mRotateLeft(false),
    mRotateRight(false),
    mTheta(0.0)
{
    if (!mTexture.loadFromFile(texturePath))
    {
        std::cerr << "Couldn't load texture: " << texturePath;
        /* TODO: What to do here? Some default shape? */
    }

    mBody.setTexture(mTexture);
    mBody.setScale(0.4, 0.4);
    const sf::Vector2f spriteSize(
        mBody.getTexture()->getSize().x * mBody.getScale().x,
        mBody.getTexture()->getSize().y * mBody.getScale().y);

    /* Approximates the center of mass as the blue "cockpit" */
    mBody.setOrigin(spriteSize.x, 1.35*spriteSize.y);
}

void Player::setImpulseUp(
    const bool choice)
{
    mImpulseUp = choice;
}

void Player::setImpulseDown(
    const bool choice)
{
    mImpulseDown = choice;
}

void Player::setRotateLeft(
    const bool choice)
{
    mRotateLeft = choice;
}

void Player::setRotateRight(
    const bool choice)
{
    mRotateRight = choice;
}

void Player::update(
    const sf::Time &deltaTime)
{
    /* For now, we'll do constant movement.
     * TODO: Add momentum, which requires a "force" balance and then
     * a velocity update. */

    // sf::Vector2f vel(0.0, 0.0);
    // float vel = 0.0;
    // if (mImpulseUp)    vel -= playerSpeed;
    // if (mImpulseDown)  vel += playerSpeed;

    float dTheta = 0.0;
    if (mRotateRight) dTheta -= playerAngularSpeed;
    if (mRotateLeft)  dTheta += playerAngularSpeed;

    mBody.rotate(dTheta*deltaTime.asSeconds());

    // sf::Vector2f dx = vel*deltaTime.asSeconds();

    // mBody.move(vel*deltaTime.asSeconds());
}

sf::Sprite &Player::get()
{
    return mBody;
}
