/**
 * @file
 *
 * $Id: MusicSystem.cpp $
 * @author Bill Eggert
 */

#include "MusicSystem.hpp"

MusicSystem::MusicSystem(
    MusicManager &musicManager,
    entityx::EventManager &eventManager):
        mMusicManager(musicManager),
        mCurrId(MusicId::StartScreen)
{
    eventManager.subscribe<LaunchGameEvent>(*this);
    eventManager.subscribe<StartGameEvent>(*this);
    eventManager.subscribe<PauseGameEvent>(*this);
    eventManager.subscribe<ResumeGameEvent>(*this);
    eventManager.subscribe<WinGameEvent>(*this);
    eventManager.subscribe<LoseGameEvent>(*this);
}

void MusicSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    /* Nothing needed. */
    (void)entities;
    (void)events;
    (void)dt;
}

void MusicSystem::receive(
    const LaunchGameEvent &event)
{
    (void)event;
    play(MusicId::StartScreen);

}

void MusicSystem::receive(
    const StartGameEvent &event)
{
    (void)event;
    play(MusicId::Playing);
}

void MusicSystem::receive(
    const PauseGameEvent &event)
{
    (void)event;
    play(MusicId::Pause);
}

void MusicSystem::receive(
    const ResumeGameEvent &event)
{
    (void)event;
    play(MusicId::Playing);
}

void MusicSystem::receive(
    const WinGameEvent &event)
{
    (void)event;
    play(MusicId::Win);
}

void MusicSystem::receive(
    const LoseGameEvent &event)
{
    (void)event;
    play(MusicId::GameOver);
}

void MusicSystem::play(
    const MusicId id)
{
    #ifdef NO_SOUND
    /* No music while debugging. */
    return;
    #endif

    /* Stop the current music. */
    {
        sf::Music &music = mMusicManager.get(mCurrId).get();
        music.stop();
    }

    /* Play the new music. */
    {
        sf::Music &music = mMusicManager.get(id).get();
        music.setLoop(true);
        music.play();
        mCurrId = id;
    }
}
