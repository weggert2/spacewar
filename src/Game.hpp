#pragma once

#include "AssetManager.hpp"

class Player;

class Game
{
public:
    Game(
        const TextureManager &textureManager,
        const SoundManager &SoundManger,
        Player &player);

    void run();

private:
    void processEvents();

    void handleKeyPress(
        const sf::Keyboard::Key key,
        const bool isPressed);

    void handleMousePress(
        const sf::Mouse::Button button,
        const bool isPressed);

    void update(
        const sf::Time &deltaTime);

    void render();

    static sf::RenderWindow defaultWindow();

private:
    sf::RenderWindow mWindow;

    const TextureManager &mTextureManager;
    const SoundManager &mSoundManger;
    Player &mPlayer;

    static constexpr int screenWidth  = 1000;
    static constexpr int screenHeight = 1000;
};
