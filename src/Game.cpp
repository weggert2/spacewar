#include "Game.hpp"

#include <iostream>

/**
 * Constructor. Sets up the window and all the actors.
 */
Game::Game():
    mWindow(sf::VideoMode(640, 480), "SpaceWar"),
    mPlayer()
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
                break;
            }
            default:
            {
                #ifdef DEBUG
                std::cout << "Unexpected event: " << event.type << '\n';
                #endif
            }
        }
    }
}

/**
 * Updates everything in the Game.
 */
void Game::update()
{
    /* TODO! */
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
