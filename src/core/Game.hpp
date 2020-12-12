/**
 * @file
 *
 * $Id: Game.hpp $
 * @author Bill Eggert
 */

#pragma once

#include "AssetManager.hpp"

#include <entityx/Event.h>
#include <entityx/Entity.h>
#include <entityx/System.h>

class GameManager;
class KeyManager;
class Player;
class QuitGameEvent;

/*
 * The monolithic game class. Responsible for running your game!
 */

class Game : public entityx::Receiver<Game>
{
public:
    Game(
        const TextureManager &textureManager,
        const SoundManager &soundManager,
        const TextManager &textManager,
        const FontManager &fontManager,
        MusicManager &musicManager,
        entityx::EventManager &eventManager,
        entityx::EntityManager &entityManager,
        entityx::SystemManager &systemManager,
        GameManager &gameManager,
        KeyManager &keyManager);

    void run();
    void receive(const QuitGameEvent &event);

private:
    void subscribeEvents();
    void buildSystems();
    void processEvents();

    void update(const sf::Time &deltaTime);
    void render(const sf::Time &deltaTime);

    void defaultWindow();

public:
    /* Misc settings */
    static constexpr int ScreenWidth  = 1920;
    static constexpr int ScreenHeight = 1080;

    /* Black hole info. */
    static constexpr float BHCenterX = ScreenWidth/2.03f;
    static constexpr float BHCenterY = ScreenHeight/2.0f;

    /* Use this radius for collision detection. */
    static constexpr float BHRadius = 190.0f;

    /* Use this factor for enemy AI to try to avoid the black hole. */
    static constexpr float BHFac = 1.25f;

    inline static sf::Vector2f getBHPos()
    {
        return sf::Vector2f(BHCenterX, BHCenterY);
    }

private:
    /* The render window */
    sf::RenderWindow mWindow;

    /* Asset managers */
    const TextureManager &mTextureManager;
    const SoundManager &mSoundManager;
    const TextManager &mTextManager;
    const FontManager &mFontManager;
    MusicManager &mMusicManager;

    /* Entity-component system */
    entityx::EventManager  &mEventManager;
    entityx::EntityManager &mEntityManager;
    entityx::SystemManager &mSystemManager;

    /* The game state stack. */
    GameManager &mGameManager;

    /* Keyboard input handler. */
    KeyManager &mKeyManager;
};
