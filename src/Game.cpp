#include "Game.hpp"

#include <iostream>

/* Debug printing. In production, you want a logging framework. */
// #define DEBUG 1

/**
 * Constructor. Sets up the window and all the actors.
 */
Game::Game():
    mWindow(sf::VideoMode(640, 480), "SpaceWar"),
    mPlayer()
{
}

/**
 * Main game loop. Processes events, updates state,
 * and renders the window.
 */
void Game::run()
{
    sf::Clock clock;
    while (mWindow.isOpen())
    {
        const sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
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
                handleKeyPress(
                    event.key.code,
                    event.type == sf::Event::KeyPressed);
            }
            break;

            case sf::Event::MouseButtonPressed:
            case sf::Event::MouseButtonReleased:
            {
                handleMousePress(
                    event.mouseButton.button,
                    event.type == sf::Event::MouseButtonPressed);
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

void Game::handleMousePress(
    const sf::Mouse::Button,
    const bool isPressed)
{
    /* TODO */
    // std::cout << isPressed << std::endl;
}

void Game::handleKeyPress(
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
            mPlayer.setImpulseUp(isPressed);
        }
        break;

        case sf::Keyboard::A:
        case sf::Keyboard::Left:
        {
            mPlayer.setImpulseLeft(isPressed);
        }
        break;

        case sf::Keyboard::S:
        case sf::Keyboard::Down:
        {
            mPlayer.setImpulseDown(isPressed);
        }
        break;

        case sf::Keyboard::D:
        case sf::Keyboard::Right:
        {
            mPlayer.setImpulseRight(isPressed);
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
void Game::update(
    const sf::Time &deltaTime)
{
    mPlayer.update(deltaTime);
}

/**
 * Renders the graphics.
 */
void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer.get());
    mWindow.display();
}
