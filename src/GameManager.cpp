#include "GameManager.hpp"

#include "EntityFactory.hpp"

#include <iostream>

GameManager::GameManager(
    const TextureManager &textureManager,
    const SoundManager &soundManager,
    const TextManager &textManager,
    const FontManager &fontManager,
    entityx::EntityManager &entityManager,
    entityx::EventManager &eventManager):
        mTextureManager(textureManager),
        mSoundManager(soundManager),
        mTextManager(textManager),
        mFontManager(fontManager),
        mEntityManager(entityManager),
        mEventManager(eventManager),
        mGameState(GameState::StartMenu)
{
    subscribeEvents();
}

void GameManager::subscribeEvents()
{
    mEventManager.subscribe<LaunchGameEvent>(*this);
    mEventManager.subscribe<StartGameEvent>(*this);
    // mEventManager.subscribe<PauseGameEvent>(*this);
    // mEventManager.subscribe<ResumeGameEvent>(*this);

    /* Note the Game class is subscribed to the QuitGameEvent directly */
}

GameState GameManager::getGameState() const
{
    return mGameState;
}

void GameManager::receive(
    const LaunchGameEvent &launch)
{
    (void)launch;

    StartMenuCreator creator(mTextManager, mFontManager);
    creator.create(mEntityManager.create());
}

void GameManager::receive(
    const StartGameEvent &event)
{
    (void)event;

    /* Blows away all the entities, which clears the menu. */
    mEntityManager.reset();

    mGameState = GameState::Playing;

    /* The background, player, and enemies are placed in the Level system. */
}
