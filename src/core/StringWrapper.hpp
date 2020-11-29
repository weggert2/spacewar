/**
 * @file
 *
 * $Id: StringWrapper.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <fstream>
#include <locale>
#include <string>
#include <sstream>

/*
 * Gives loading a string from file the same interface as the SFML asset
 * loading, so we can use the same API.
 */

class StringWrapper
{
public:
    const std::wstring &get() const
    {
        return mStr;
    }

    bool loadFromFile(
        const std::string &filename)
    {
        std::wifstream stream(filename);
        if (!stream)
        {
            return false;
        }

        #ifdef _WIN32
            stream.imbue(std::locale(
                std::locale::empty(),
                new std::codecvt_utf8<wchar_t>));
        #else
            stream.imbue(std::locale("en_US.UTF-8"));
        #endif

        std::wstringstream wss;
        wss << stream.rdbuf();
        mStr = wss.str();

        return true;
    }

private:
    std::wstring mStr;
};
