#include "Player.hpp"

#include "math_utils.hpp"

#include <cmath>
#include <iostream>

/** Hard code the texture path. Not amazing, but it'll get us going. */
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

    /* Approximates the center of mass as the blue "cockpit" */
    const auto size  = mBody.getTexture()->getSize();
    const auto scale = mBody.getScale();
    const sf::Vector2f spriteSize(
        size.x * scale.x,
        size.y * scale.y);

    /* 1.35 = magic number found by fiddling. */
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
    /* For now, we'll do constant linear velocity.
     * TODO: Add momentum, which requires a "force" balance and then
     * a velocity update. */

    /* Angular and linear velocity */
    float omega = 0.0;
    float vel = 0.0;
    if (mRotateRight) omega += playerAngularSpeed;
    if (mRotateLeft)  omega -= playerAngularSpeed;
    if (mImpulseUp)   vel   -= playerLinearSpeed;
    if (mImpulseDown) vel   += playerLinearSpeed;

    const float dt = deltaTime.asSeconds();
    const float dTheta = omega*dt;
    mBody.rotate(dTheta);

    /* Rotate the unit y vector by theta to get the heading direction.
     * There's probably a better way to do this with SFML transforms, or
     * by leveraging a more robust library like Eigen, but this math is
     * easy enough that we don't worry about it. */
    const float theta = toRad(mBody.getRotation());
    const sf::Vector2f n(-std::sin(theta), std::cos(theta));
    mBody.move(vel*dt*n);
}

sf::Sprite &Player::get()
{
    return mBody;
}
