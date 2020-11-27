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

class Game
{
public:
    Game(
        const TextureManager &textureManager,
        const SoundManager &soundManager,
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

    void update(
        const sf::Time &deltaTime);

    void render();

    static sf::RenderWindow defaultWindow();

private:
    sf::RenderWindow mWindow;

    const TextureManager &mTextureManager;
    const SoundManager &mSoundManager;
    KeyManager &mKeyManager;

    entityx::EventManager  &mEventManager;
    entityx::EntityManager &mEntityManager;
    entityx::SystemManager &mSystemManager;

    GameManager &mGameManager;

    Player &mPlayer;

    static constexpr int screenWidth  = 1000;
    static constexpr int screenHeight = 1000;
};
