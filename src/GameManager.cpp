#include "GameManager.hpp"
#include "EntityFactory.hpp"
#include "components/Menu.hpp"

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
    mEventManager.subscribe<PauseGameEvent>(*this);
    mEventManager.subscribe<ResumeGameEvent>(*this);
    mEventManager.subscribe<ShowControlsEvent>(*this);
    mEventManager.subscribe<ShowCreditsEvent>(*this);
    mEventManager.subscribe<WinGameEvent>(*this);
    mEventManager.subscribe<LoseGameEvent>(*this);

    /* Note the Game class is subscribed to the QuitGameEvent directly */
}

GameState GameManager::getGameState() const
{
    return mGameState;
}

void GameManager::receive(
    const LaunchGameEvent &event)
{
    (void)event;

    StartMenuCreator creator(
        mTextManager.get(TextId::Logo).get(),
        mFontManager.get(FontId::Logo),
        mFontManager.get(FontId::Menu),
        *this);

    creator.create(mEntityManager.create());
}

void GameManager::receive(
    const StartGameEvent &event)
{
    (void)event;

    Menu::Handle menu;
    for (entityx::Entity e : mEntityManager.entities_with_components(menu))
    {
        e.destroy();
    }

    mGameState = GameState::Playing;

    /* The background, player, and enemies are placed in the Stage system. */
}

void GameManager::receive(
    const ResumeGameEvent &event)
{
    /* We want to do the same thing as a StartGameEvent. We just don't
     * want an _actual_ StartGameEvent, since that has other implications with
     * systems like the StageSystem. Therefore, just defer to the relevant
     * 'receive' method here. */
    (void)event;
    StartGameEvent dummyEvent;

    receive(dummyEvent);
}

void GameManager::receive(
    const PauseGameEvent &event)
{
    (void)event;
    mGameState = GameState::Paused;

    StartMenuCreator creator(
        mTextManager.get(TextId::Pause).get(),
        mFontManager.get(FontId::Pause),
        mFontManager.get(FontId::Menu),
        *this);

    creator.create(mEntityManager.create());
}

void GameManager::receive(
    const ShowControlsEvent &event)
{
    (void)event;

    Menu::Handle menu;
    for (entityx::Entity e : mEntityManager.entities_with_components(menu))
    {
        e.destroy();
    }

    StartMenuCreator creator(
        mTextManager.get(TextId::Controls).get(),
        mFontManager.get(FontId::Pause),
        mFontManager.get(FontId::Menu),
        *this);

    creator.create(mEntityManager.create());
}

void GameManager::receive(
    const ShowCreditsEvent &event)
{
    (void)event;

    Menu::Handle menu;
    for (entityx::Entity e : mEntityManager.entities_with_components(menu))
    {
        e.destroy();
    }

    StartMenuCreator creator(
        mTextManager.get(TextId::Credits).get(),
        mFontManager.get(FontId::Menu),
        mFontManager.get(FontId::Menu),
        *this,
        30);

    creator.create(mEntityManager.create());
}

void GameManager::receive(
    const WinGameEvent &event)
{
    (void)event;

    Menu::Handle menu;
    for (entityx::Entity e : mEntityManager.entities_with_components(menu))
    {
        e.destroy();
    }

    mGameState = GameState::GameOver;

    StartMenuCreator creator(
        mTextManager.get(TextId::Win).get(),
        mFontManager.get(FontId::Pause),
        mFontManager.get(FontId::Menu),
        *this);

    creator.create(mEntityManager.create());
}

void GameManager::receive(
    const LoseGameEvent &event)
{
    (void)event;

    mEntityManager.reset();
    mGameState = GameState::GameOver;

    StartMenuCreator creator(
        mTextManager.get(TextId::GameOver).get(),
        mFontManager.get(FontId::Pause),
        mFontManager.get(FontId::Menu),
        *this);

    creator.create(mEntityManager.create());
}
