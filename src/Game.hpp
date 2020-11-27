#pragma once

#include "AssetManager.hpp"

namespace entityx
{
    class EventManager;
    class EntityManager;
    class SystemManager;
}

class GameManager;
class KeyManager;
class Player;

/*
 * The monolithic game class. Responsible for running your game!
 */

class Game
{
public:
    Game(
        const TextureManager &textureManager,
        const SoundManager &soundManager,
        const TextManager &textManager,
        const FontManager &fontManager,
        entityx::EventManager &eventManager,
        entityx::EntityManager &entityManager,
        entityx::SystemManager &systemManager,
        GameManager &gameManager,
        KeyManager &keyManager,
        Player &player);

    void run();

private:
    void subscribeEvents();
    void buildSystems();

    void processEvents();

    void update(const sf::Time &deltaTime);
    void render(const sf::Time &deltaTime);

    static sf::RenderWindow defaultWindow();

public:
    /* Misc settings */
    static constexpr int screenWidth  = 1000;
    static constexpr int screenHeight = 1000;

private:
    /* The render window */
    sf::RenderWindow mWindow;

    /* Asset managers */
    const TextureManager &mTextureManager;
    const SoundManager &mSoundManager;
    const TextManager &mTextManager;
    const FontManager &mFontManager;

    /* Keyboard input handler. */
    KeyManager &mKeyManager;

    /* Entity-component system */
    entityx::EventManager  &mEventManager;
    entityx::EntityManager &mEntityManager;
    entityx::SystemManager &mSystemManager;

    /* The game state stack. */
    GameManager &mGameManager;

    /* The player. */
    Player &mPlayer;
};
