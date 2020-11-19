#pragma once

#include "Player.hpp"

class AssetManager;

class Game
{
public:
    explicit Game(AssertManager &assetManager);

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


private:
    AssetManager &mAssetManager;
    sf::RenderWindow mWindow;
    Player mPlayer;

    static constexpr int screenWidth  = 1000;
    static constexpr int screenHeight = 1000;
};
