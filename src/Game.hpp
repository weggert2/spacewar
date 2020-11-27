#pragma once

#include "AssetManager.hpp"

namespace entityx
{
    class EventManager;
    class EntityManager;
    class SystemManager;
}

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
        KeyManager &keyManager,
        Player &player);

    void run();

private:
    void subscribeEvents();
    void buildSystems();

    void processEvents();

    void handleKeyPress(
        const sf::Keyboard::Key key,
        const bool isPressed);

    void handleMousePress(
        const sf::Mouse::Button button,
        const bool isPressed);

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

    Player &mPlayer;

    static constexpr int screenWidth  = 1000;
    static constexpr int screenHeight = 1000;
};
