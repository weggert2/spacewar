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
    /* If key is not in the map already, C++ makes an entry for us.
     * I don't like to rely on that behavior though, so we'll add
     * in a bit of extra logic. */

    const auto found = pressedMap.find(key);
    if (found == pressedMap.end())
    {
        return false;
    }

    return pressedMap.at(key);
}
