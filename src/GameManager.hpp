#pragma once

#include "AssetManager.hpp"
#include "Events.hpp"

#include <entityx/Event.h>
#include <entityx/Entity.h>

enum class GameState
{
    StartMenu,
    Playing,
    Paused,
    GameOver,
    Unknown,
};

/**
 * The state stack
 */

class GameManager : public entityx::Receiver<GameManager>
{
public:
    GameManager(
        const TextureManager &textureManager,
        const SoundManager &soundManager,
        const TextManager &textManager,
        const FontManager &fontManager,
        entityx::EntityManager &entityManager,
        entityx::EventManager &eventManager);

    void receive(const LaunchGameEvent &launch);
    void receive(const StartGameEvent &start);
    // void receive(const QuitGameEvent &quit);
    // void receive(const PauseGameEvent &pause);
    // void receive(const ResumeGameEvent &resume);

private:
    void subscribeEvents();

private:
    /* Asset managers */
    const TextureManager &mTextureManager;
    const SoundManager &mSoundManager;
    const TextManager &mTextManager;
    const FontManager &mFontManager;

    /* Entity-component system. */
    entityx::EntityManager &mEntityManager;
    entityx::EventManager &mEventManager;

    /* Current game state. */
    GameState mGameState;
};
