#pragma once

#include "AssetManager.hpp"
#include "Events.hpp"

#include <entityx/Event.h>
#include <entityx/Entity.h>
#include <entityx/System.h>

enum class GameState
{
    StartMenu,
    Playing,
    Paused,
    Controls,
    Scores,
    GameOver,
};

class PlayerScoreSystem;

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
        const MusicManager &musicManager,
        entityx::EntityManager &entityManager,
        entityx::EventManager &eventManager,
        entityx::SystemManager &systemManager);

    GameState getGameState() const;

    void receive(const LaunchGameEvent &event);
    void receive(const StartGameEvent &event);
    void receive(const ResumeGameEvent &event);
    void receive(const PauseGameEvent &event);
    void receive(const ShowControlsEvent &event);
    void receive(const ShowCreditsEvent &event);
    void receive(const ShowScoresEvent &event);
    void receive(const WinGameEvent &event);
    void receive(const LoseGameEvent &event);

private:
    void subscribeEvents();
    void destroyMenus();

private:
    /* Asset managers */
    const TextureManager &mTextureManager;
    const SoundManager &mSoundManager;
    const TextManager &mTextManager;
    const FontManager &mFontManager;
    const MusicManager &mMusicManager;

    /* Entity-component system. */
    entityx::EntityManager &mEntityManager;
    entityx::EventManager &mEventManager;
    entityx::SystemManager &mSystemManager;

    /* Current game state. */
    GameState mGameState;
};
