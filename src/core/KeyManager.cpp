/**
 * @file
 *
 * $Id: KeyManager.cpp $
 * @author Bill Eggert
 */

#include "KeyManager.hpp"

void KeyManager::updateKey(
    const sf::Keyboard::Key key,
    const bool pressed)
{
    pressedMap[key] = pressed;
}

bool KeyManager::isPressed(
    const sf::Keyboard::Key key) const
{
    const auto found = pressedMap.find(key);
    if (found == pressedMap.end())
    {
        return false;
    }

    return found->second;
}
