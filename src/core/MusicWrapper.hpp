#pragma once

#include <SFML/Audio/Music.hpp>

/*
 * Gives loading music from file the same interface as the SFML asset
 * loading, so we can use the same API.
 */

class MusicWrapper
{
public:
    const sf::Music &get() const
    {
        return mMusic;
    }

    sf::Music &get()
    {
        return mMusic;
    }

    bool loadFromFile(
        const std::string &filename)
    {
        return mMusic.openFromFile(filename);
    }

private:
    sf::Music mMusic;
};
