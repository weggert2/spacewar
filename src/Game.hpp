#pragma once

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();

    void run();

private:
    void processEvents();

    void handlePlayerInput(
        const sf::Keyboard::Key key,
        const bool isPressed);

    void update();
    void render();


private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;

    bool mPlayerMovingUp;
    bool mPlayerMovingLeft;
    bool mPlayerMovingDown;
    bool mPlayerMovingRight;
};
