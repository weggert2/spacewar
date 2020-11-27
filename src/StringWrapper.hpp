#pragma once

#include <fstream>
#include <string>

/*
 * Gives loading a string from file the same interface as the SFML asset
 * loading, so we can use the same API.
 */

class StringWrapper
{
public:
    const std::string &get() const
    {
        return mStr;
    }

    bool loadFromFile(
        const std::string &filename)
    {
        std::ifstream stream(filename);
        if (!stream)
        {
            return false;
        }

        mStr = std::string(
            std::istreambuf_iterator<char>(stream),
            std::istreambuf_iterator<char>());

        return true;
    }

private:
    std::string mStr;
};
