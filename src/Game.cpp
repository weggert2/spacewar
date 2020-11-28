#include "Game.hpp"

#include "GameManager.hpp"
#include "Events.hpp"
#include "KeyManager.hpp"

#include "systems/MenuSystem.hpp"
#include "systems/Movement.hpp"
#include "systems/PlayerControlSystem.hpp"
#include "systems/Render.hpp"
#include "systems/Stage.hpp"

#include <iostream>

/* Debug printing. In production, you want a logging framework. */
// #define DEBUG 1

Game::Game(
    const TextureManager &textureManager,
    const SoundManager &soundManager,
    const TextManager &textManager,
    const FontManager &fontManager,
    entityx::EventManager &eventManager,
    entityx::EntityManager &entityManager,
    entityx::SystemManager &systemManager,
    GameManager &gameManager,
    KeyManager &keyManager):
        mWindow(defaultWindow()),
        mTextureManager(textureManager),
        mSoundManager(soundManager),
        mTextManager(textManager),
        mFontManager(fontManager),
        mEventManager(eventManager),
        mEntityManager(entityManager),
        mSystemManager(systemManager),
        mGameManager(gameManager),
        mKeyManager(keyManager)
{
    subscribeEvents();
    buildSystems();

    /* Get things kicked off. */
    mEventManager.emit<LaunchGameEvent>();
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

        render(timePerFrame);
    }
}

void Game::subscribeEvents()
{
    /* Connect the event manager to the events. */
    // mEventManager.subscribe<StartGameEvent>(*this);
    mEventManager.subscribe<QuitGameEvent>(*this);
}

void Game::buildSystems()
{
    /* Build the 'system' part of entity component system */
    mSystemManager.add<Render>(mWindow, mTextureManager);
    mSystemManager.add<MenuSystem>(mWindow, mEntityManager, mEventManager);
    mSystemManager.add<Stage>(mTextureManager, mEntityManager, mEventManager);
    mSystemManager.add<PlayerControlSystem>(mKeyManager);
    mSystemManager.add<Movement>();

    /* Required by entityx to be called after all the systems are added. */
    mSystemManager.configure();
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
                const auto key = event.key.code;
                const bool isPressed = event.type == sf::Event::KeyPressed;
                mEventManager.emit<KeyboardEvent>(key, isPressed);
                mKeyManager.updateKey(key, isPressed);
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

void Game::receive(const QuitGameEvent &event)
{
    (void)event;
    mWindow.close();
}

void Game::update(
    const sf::Time &deltaTime)
{
    if (mGameManager.getGameState() != GameState::Playing)
    {
        return;
    }

    const float dt = deltaTime.asSeconds();

    mSystemManager.update<PlayerControlSystem>(dt);
    mSystemManager.update<Movement>(dt);
    mSystemManager.update<Stage>(dt);
}

void Game::render(
    const sf::Time &deltaTime)
{
    const float dt = deltaTime.asSeconds();

    mWindow.clear();

    /* Render the things that need rendering. */
    mSystemManager.update<Render>(dt);
    mSystemManager.update<MenuSystem>(dt);

    // mWindow.draw(mPlayer.get());
    mWindow.display();
}

sf::RenderWindow Game::defaultWindow()
{
    return sf::RenderWindow(
        sf::VideoMode(screenWidth, screenHeight),
        "SpaceWar",
        sf::Style::Titlebar | sf::Style::Close);
}
