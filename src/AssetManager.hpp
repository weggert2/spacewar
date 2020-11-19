#pragma once

#include "SoundId.hpp"
#include "TextureId.hpp"

#include <iostream>
#include <string>
#include <unordered_map>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// TODO: Better error messages when things fail to load or get.

template <typename AssetType, typename AssetId>
class AssetManager
{
public:
    ~AssetManager()
    {
        /* Prefer raw pointers to std::unique_ptr for performance. */
        for (auto &assetPair : mAssetMap)
        {
            delete assetPair.second;
        }
    }

    bool load(
        const AssetId id,
        const std::string &filename)
    {
        AssetType *asset = new AssetType();
        if (!asset->loadFromFile(filename))
        {
            std::cerr << "Could not load asset " << filename << '\n';
            return false;
        }

        mAssetMap[id] = asset;
        return true;
    }

    bool get(
        const AssetId id,
        AssetType &asset) const
    {
        const auto found = mAssetMap.find(id);
        if (found == mAssetMap.end())
        {
            std::cerr << "Could not get asset\n";
            return false;
        }

        asset = *found->second;
        return true;
    }

private:
    std::unordered_map<AssetId, AssetType *> mAssetMap;
};

/* Convenience typedefs. */
typedef AssetManager<sf::Texture,     TextureId> TextureManager;
typedef AssetManager<sf::SoundBuffer, SoundId>   SoundManager;
