#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Player
{
public:
    Player();

    sf::Sprite &get();

    void setImpulseUp(const bool choice);
    void setImpulseDown(const bool choice);
    void setRotateLeft(const bool choice);
    void setRotateRight(const bool choice);

    void update(
        const sf::Time &deltaTime);

public:

private:
    sf::Sprite mBody;
    sf::Texture mTexture;

    bool mImpulseUp;
    bool mImpulseDown;
    bool mRotateLeft;
    bool mRotateRight;

    static constexpr float playerLinearSpeed = 200.0;
    static constexpr float playerAngularSpeed = 100.0;
    static const std::string texturePath;

    float mTheta;
};
