#pragma once

#include "Player.hpp"

class Game
{
public:
    Game();

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
    sf::RenderWindow mWindow;
    Player mPlayer;

    static constexpr int screenWidth  = 1000;
    static constexpr int screenHeight = 1000;
};
