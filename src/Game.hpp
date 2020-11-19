#pragma once

#include "AssetManager.hpp"
#include "Player.hpp"

class Game
{
public:
    Game(
        const TextureManager &textureManager,
        const SoundManager &SoundManger);

    void run();

private:
    void processEvents();

    void handleKeyPress(
        const sf::Keyboard::Key key,
        const bool isPressed);

    void handleMousePress(
        const sf::Mouse::Button,
        const bool isPressed);

    void update(
        const sf::Time &deltaTime);

    void render();

    static sf::RenderWindow defaultWindow();

private:
    const TextureManager &mTextureManager;
    const SoundManager &mSoundManger;

    sf::RenderWindow mWindow;
    Player mPlayer;

    static constexpr int screenWidth  = 1000;
    static constexpr int screenHeight = 1000;
};
