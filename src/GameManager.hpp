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

    GameState getGameState() const;

    void receive(const LaunchGameEvent &event);
    void receive(const StartGameEvent &event);
    void receive(const ResumeGameEvent &event);
    void receive(const PauseGameEvent &event);

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
