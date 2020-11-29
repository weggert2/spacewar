/**
 * @file
 *
 * $Id: KeyManager.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <unordered_map>

class KeyManager
{
public:
    void updateKey(
        const sf::Keyboard::Key key,
        const bool pressed);

    bool isPressed(
        const sf::Keyboard::Key key) const;

private:
    std::unordered_map<sf::Keyboard::Key, bool> pressedMap;
};
