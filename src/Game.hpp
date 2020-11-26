#pragma once

#include "AssetManager.hpp"

#include <entityx/System.h>

class Player;

class Game
{
public:
    Game(
        const TextureManager &textureManager,
        const SoundManager &soundManager,
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
    const SoundManager &mSoundManager;

    entityx::EventManager mEventManager;
    entityx::EntityManager mEntityManager;


    Player &mPlayer;

    static constexpr int screenWidth  = 1000;
    static constexpr int screenHeight = 1000;
};
