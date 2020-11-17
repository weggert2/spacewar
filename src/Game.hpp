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

    void update();
    void render();


private:
    sf::RenderWindow mWindow;
    Player mPlayer;

    bool mImpulseUp;
    bool mImpulseLeft;
    bool mImpulseDown;
    bool mImpulseRight;
};
