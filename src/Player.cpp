#include "Player.hpp"

#include "math_utils.hpp"

#include <cmath>
#include <iostream>

/* Hard code the texture path. Not amazing, but it'll get us going. */
const std::string Player::texturePath = "../assets/textures/blue/ship.png";

Player::Player():
    mBody(),
    velocity(0.0f),
    omega(0.0f)
{
    if (!mTexture.loadFromFile(texturePath))
    {
        std::cerr << "Couldn't load texture: " << texturePath;
        /* TODO: What to do here? Some default shape? */
    }

    mBody.setTexture(mTexture);
    mBody.setScale(0.4f, 0.4f);

    /* Approximates the center of mass as the blue "cockpit" */
    const auto size  = mBody.getTexture()->getSize();
    const auto scale = mBody.getScale();
    const sf::Vector2f spriteSize(
        size.x * scale.x,
        size.y * scale.y);

    /* 1.35 = magic number found by fiddling. */
    mBody.setOrigin(spriteSize.x, 1.35f*spriteSize.y);
}

void Player::setImpulseUp(
    const bool choice)
{
    velocity = choice ? -playerLinearSpeed : 0.0f;
}

void Player::setImpulseDown(
    const bool choice)
{
    velocity = choice ? playerLinearSpeed : 0.0f;
}

void Player::setRotateLeft(
    const bool choice)
{
    omega = choice ? -playerAngularSpeed : 0.0f;
}

void Player::setRotateRight(
    const bool choice)
{
    omega = choice ? playerAngularSpeed : 0.0f;
}

void Player::update(
    const sf::Time &deltaTime)
{
    /* For now, we'll do constant linear velocity.
     * TODO: Add momentum, which requires a "force" balance and then
     * a velocity update. */

    const float dt = deltaTime.asSeconds();
    const float dTheta = omega*dt;
    mBody.rotate(dTheta);

    /* Rotate the unit y vector by theta to get the heading direction. */
    const float theta = toRad(mBody.getRotation());
    const sf::Vector2f n(-std::sin(theta), std::cos(theta));
    mBody.move(velocity*n*dt);
}

sf::Sprite &Player::get()
{
    return mBody;
}
