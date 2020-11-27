#pragma once

/* Defines the events that can be emitted / received. */

#include <entityx/Entity.h>
#include <entityx/Event.h>
#include <SFML/Window/Keyboard.hpp>

class LaunchGameEvent   : public entityx::Event<LaunchGameEvent>   {};
class StartGameEvent    : public entityx::Event<StartGameEvent>    {};
class QuitGameEvent     : public entityx::Event<QuitGameEvent>     {};
class StageClearedEvent : public entityx::Event<StageClearedEvent> {};
class PauseGameEvent    : public entityx::Event<PauseGameEvent>    {};
class ResumeGameEvent   : public entityx::Event<ResumeGameEvent>   {};

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
