#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Player
{
public:
    Player();

    sf::Sprite &get();

    void setImpulseUp(const bool choice);
    void setImpulseLeft(const bool choice);
    void setImpulseDown(const bool choice);
    void setImpulseRight(const bool choice);

    void update(
        const sf::Time &deltaTime);

public:

private:
    sf::Sprite mBody;
    sf::Texture mTexture;

    bool mImpulseUp;
    bool mImpulseLeft;
    bool mImpulseDown;
    bool mImpulseRight;

    static constexpr float playerSpeed = 200.0;
    static const std::string texturePath;
};
