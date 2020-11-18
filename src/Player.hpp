#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();

    sf::CircleShape &get();

    void setImpulseUp(const bool choice);
    void setImpulseLeft(const bool choice);
    void setImpulseDown(const bool choice);
    void setImpulseRight(const bool choice);

    void update(
        const sf::Time &deltaTime);

public:
    static constexpr float playerSpeed = 100.0;

private:
    /* We'll make this a sprite at some point. */
    sf::CircleShape mBody;

    bool mImpulseUp;
    bool mImpulseLeft;
    bool mImpulseDown;
    bool mImpulseRight;
};
