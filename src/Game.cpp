#include "Game.hpp"

#include "Player.hpp"

#include <iostream>

/* Debug printing. In production, you want a logging framework. */
// #define DEBUG 1

Game::Game(
    const TextureManager &textureManager,
    const SoundManager &soundManager,
    Player &player):
        mWindow(defaultWindow()),
        mTextureManager(textureManager),
        mSoundManager(soundManager),
        mEventManager(),
        mEntityManager(mEventManager),
        mPlayer(player)
{
    /* Move the player to the lower right of the screen. */
    mPlayer.get().move(0.8f*screenWidth, 0.8f*screenHeight);
}

void Game::run()
{
    /* Use a fixed time step update. */
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    static const sf::Time timePerFrame = sf::seconds(1.0f/60.0f);

    while (mWindow.isOpen())
    {
        const sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;

        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            processEvents();
            update(timePerFrame);
        }

        render();
    }
}

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
    const sf::Mouse::Button button,
    const bool isPressed)
{
    /* TODO */
    (void)button;
    (void)isPressed;
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

        case sf::Keyboard::S:
        case sf::Keyboard::Down:
        {
            mPlayer.setImpulseDown(isPressed);
        }
        break;

        case sf::Keyboard::A:
        case sf::Keyboard::Left:
        {
            mPlayer.setRotateLeft(isPressed);
        }
        break;

        case sf::Keyboard::D:
        case sf::Keyboard::Right:
        {
            mPlayer.setRotateRight(isPressed);
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

void Game::update(
    const sf::Time &deltaTime)
{
    mPlayer.update(deltaTime);
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer.get());
    mWindow.display();
}

sf::RenderWindow Game::defaultWindow()
{
    return sf::RenderWindow(
        sf::VideoMode(screenWidth, screenHeight),
        "SpaceWar",
        sf::Style::Titlebar | sf::Style::Close);
}
