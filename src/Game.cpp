#include "Game.hpp"

#include <iostream>

/* Debug printing. In production, you want a logging framework. */
// #define DEBUG 1

/**
 * Constructor. Sets up the window and all the actors.
 */
Game::Game():
    mWindow(sf::VideoMode(640, 480), "SpaceWar"),
    mPlayer(),
    mPlayerMovingUp(false),
    mPlayerMovingLeft(false),
    mPlayerMovingDown(false),
    mPlayerMovingRight(false)
{
    mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f, 100.f);
    mPlayer.setFillColor(sf::Color::Cyan);
}

/**
 * Main game loop. Processes events, updates state,
 * and renders the window.
 */
void Game::run()
{
    while (mWindow.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

/**
 * Process events like key presses.
 */
void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
            {
                mWindow.close();
            }
            break;

            case sf::Event::KeyPressed:
            case sf::Event::KeyReleased:
            {
                handlePlayerInput(
                    event.key.code,
                    event.type == sf::Event::KeyPressed);
            }
            break;

            {
                const bool pressed = false;
                handlePlayerInput(event.key.code, pressed);
            }
            break;

            default:
            {
                #ifdef DEBUG
                std::cout << "Unexpected event: " << event.type << '\n';
                #endif
            }
        }
    }
}

void Game::handlePlayerInput(
    const sf::Keyboard::Key key,
    const bool isPressed)
{
    /* Note - multiple keyboard presses are processed in sequential events,
     * so we can treat these as single events. */

    switch(key)
    {
        case sf::Keyboard::W:
        case sf::Keyboard::Up:
        {
            mPlayerMovingUp = isPressed;
        }
        break;

        case sf::Keyboard::A:
        case sf::Keyboard::Left:
        {
            mPlayerMovingLeft = isPressed;
        }
        break;

        case sf::Keyboard::S:
        case sf::Keyboard::Down:
        {
            mPlayerMovingDown = isPressed;
        }
        break;

        case sf::Keyboard::D:
        case sf::Keyboard::Right:
        {
            mPlayerMovingRight = isPressed;
        }
        break;

        default:
        {
            #ifdef DEBUG
            std::cout << "Unexpected key press: " << key << '\n';
            #endif
        }
    }
}

/**
 * Updates everything in the Game.
 */
void Game::update()
{
    sf::Vector2f movement(0.0, 0.0);
}

/**
 * Renders the graphics.
 */
void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}
