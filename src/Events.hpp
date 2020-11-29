#pragma once

/* Defines the events that can be emitted / received. */

#include "AssetManager.hpp"

#include <entityx/Entity.h>
#include <entityx/Event.h>
#include <SFML/Window/Keyboard.hpp>

class LaunchGameEvent   : public entityx::Event<LaunchGameEvent>   {};
class StartGameEvent    : public entityx::Event<StartGameEvent>    {};
class QuitGameEvent     : public entityx::Event<QuitGameEvent>     {};
class StageClearedEvent : public entityx::Event<StageClearedEvent> {};
class PauseGameEvent    : public entityx::Event<PauseGameEvent>    {};
class ResumeGameEvent   : public entityx::Event<ResumeGameEvent>   {};
class ShowControlsEvent : public entityx::Event<ShowControlsEvent> {};
class ShowCreditsEvent  : public entityx::Event<ShowCreditsEvent>  {};
class ShowScoresEvent   : public entityx::Event<ShowScoresEvent>   {};
class WinGameEvent      : public entityx::Event<WinGameEvent>      {};
class LoseGameEvent     : public entityx::Event<LoseGameEvent>     {};

class KeyboardEvent : public entityx::Event<KeyboardEvent>
{
public:
    KeyboardEvent(
        const sf::Keyboard::Key key,
        const bool pressed):
            mKey(key),
            mPressed(pressed)
    {
    }

    sf::Keyboard::Key getKey() const { return mKey; }
    bool getPressed() const { return mPressed; }

private:
    const sf::Keyboard::Key mKey;
    const bool mPressed;
};

class EnemyDestroyedEvent : public entityx::Event<EnemyDestroyedEvent>
{
public:
    explicit EnemyDestroyedEvent(
        const float pointValue):
            mPointValue(pointValue)
    {
    }

    float getPointValue() const { return mPointValue;  }

private:
    const float mPointValue;
};

class PlaySoundEvent : public entityx::Event<PlaySoundEvent>
{
public:
    explicit PlaySoundEvent(
        const SoundId soundId):
            mSoundId(soundId)
    {
    }

    SoundId get() const
    {
        return mSoundId;
    }

private:
    const SoundId mSoundId;
};

class PlayMusicEvent : public entityx::Event<PlayMusicEvent>
{
public:
    explicit PlayMusicEvent(
        const MusicId musicId):
            mMusicId(musicId)
    {
    }

    MusicId get() const
    {
        return mMusicId;
    }

private:
    const MusicId mMusicId;
};
