/**
 * @file
 *
 * $Id: Game.cpp $
 * @author Bill Eggert
 */

#include "Game.hpp"

#include "GameManager.hpp"
#include "Events.hpp"
#include "KeyManager.hpp"

#include "systems/CollisionSystem.hpp"
#include "systems/EnemyControlSystem.hpp"
#include "systems/MenuSystem.hpp"
#include "systems/MovementSystem.hpp"
#include "systems/MusicSystem.hpp"
#include "systems/PlayerControlSystem.hpp"
#include "systems/PlayerDeathSystem.hpp"
#include "systems/PlayerScoreSystem.hpp"
#include "systems/ProjectileDurationSystem.hpp"
#include "systems/RenderSystem.hpp"
#include "systems/SoundSystem.hpp"
#include "systems/StageSystem.hpp"
#include "systems/WeaponSystem.hpp"

#include <iostream>

const float Game::BHRadius = 190.0f;
const float Game::BHFac = 1.25f;

Game::Game(
    const TextureManager &textureManager,
    const SoundManager &soundManager,
    const TextManager &textManager,
    const FontManager &fontManager,
    MusicManager &musicManager,
    entityx::EventManager &eventManager,
    entityx::EntityManager &entityManager,
    entityx::SystemManager &systemManager,
    GameManager &gameManager,
    KeyManager &keyManager):
        mWindow(),
        mTextureManager(textureManager),
        mSoundManager(soundManager),
        mTextManager(textManager),
        mFontManager(fontManager),
        mMusicManager(musicManager),
        mEventManager(eventManager),
        mEntityManager(entityManager),
        mSystemManager(systemManager),
        mGameManager(gameManager),
        mKeyManager(keyManager)
{
    defaultWindow();
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
    mEventManager.subscribe<QuitGameEvent>(*this);
}

void Game::buildSystems()
{
    /* Build the 'system' part of entity component system */
    mSystemManager.add<RenderSystem>(mWindow, mTextureManager);
    mSystemManager.add<MenuSystem>(mWindow, mEntityManager, mEventManager);
    mSystemManager.add<StageSystem>(mTextureManager, mEntityManager, mEventManager);
    mSystemManager.add<PlayerControlSystem>(mKeyManager);
    mSystemManager.add<PlayerDeathSystem>();
    mSystemManager.add<MovementSystem>();
    mSystemManager.add<WeaponSystem>(mTextureManager);
    mSystemManager.add<ProjectileDurationSystem>();
    mSystemManager.add<CollisionSystem>(mEventManager);
    mSystemManager.add<PlayerScoreSystem>(mEventManager);
    mSystemManager.add<SoundSystem>(mSoundManager, mEventManager);
    mSystemManager.add<MusicSystem>(mMusicManager, mEventManager);
    mSystemManager.add<EnemyControlSystem>();

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
                // std::cout << "Unexpected event: " << event.type << '\n';
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

    mSystemManager.update<StageSystem>(dt);
    mSystemManager.update<PlayerControlSystem>(dt);
    mSystemManager.update<PlayerDeathSystem>(dt);
    mSystemManager.update<MovementSystem>(dt);
    mSystemManager.update<WeaponSystem>(dt);
    mSystemManager.update<ProjectileDurationSystem>(dt);
    mSystemManager.update<CollisionSystem>(dt);
    mSystemManager.update<PlayerScoreSystem>(dt);
    mSystemManager.update<SoundSystem>(dt);
    mSystemManager.update<MusicSystem>(dt);
    mSystemManager.update<EnemyControlSystem>(dt);
}

void Game::render(
    const sf::Time &deltaTime)
{
    const float dt = deltaTime.asSeconds();

    mWindow.clear();

    /* Render the things that need rendering. */
    mSystemManager.update<RenderSystem>(dt);
    mSystemManager.update<MenuSystem>(dt);

    /* For finding where the black hole is. */
    // sf::CircleShape circle(BHRadius);
    // circle.setOrigin(BHRadius,BHRadius);
    // circle.setPosition(sf::Vector2f(BHCenterX, BHCenterY));
    // mWindow.draw(circle);

    mWindow.display();
}

void Game::defaultWindow()
{
    auto monitorSize = sf::VideoMode::getDesktopMode();
    const std::string name = "SpaceWar";

    if (monitorSize.width == ScreenWidth &&
        monitorSize.height == ScreenHeight)
    {
        mWindow.create(sf::VideoMode(), name, sf::Style::Fullscreen);
    }
    else
    {

        mWindow.create(
            sf::VideoMode(ScreenWidth, ScreenHeight),
            name,
            sf::Style::Titlebar | sf::Style::Close);
    }
}
