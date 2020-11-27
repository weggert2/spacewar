#pragma once

/* Defines the events that can be emitted / received. */

#include <entityx/Entity.h>
#include <entityx/Event.h>

class StartGameEvent : public entityx::Event<StartGameEvent> {};
class QuitGameEvent  : public entityx::Event<QuitGameEvent>  {};

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
