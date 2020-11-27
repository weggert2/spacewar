#pragma once

#include <entityx/Entity.h>
#include <SFML/Graphics.hpp>

// class Player : public entityx::Component<Player>
// {
// public:
//     explicit Player(
//         const sf::Texture &texture);

// public:
//     sf::Sprite mSprite;
// };

// #include <SFML/Graphics.hpp>

// class Player
// {
// public:
//     explicit Player(
//         const sf::Texture &texture);

//     sf::Sprite &get();

//     void setImpulseUp(const bool choice);
//     void setImpulseDown(const bool choice);
//     void setRotateLeft(const bool choice);
//     void setRotateRight(const bool choice);

//     void update(
//         const sf::Time &deltaTime);

// private:
//     sf::Sprite mBody;

//     /** The linear ang angular velocities. */
//     float velocity;
//     float omega;

//     static constexpr float playerLinearSpeed = 200.0;
//     static constexpr float playerAngularSpeed = 100.0;
//     static const std::string texturePath;
// };
