#pragma once

#include "SoundId.hpp"
#include "TextureId.hpp"

#include <iostream>
#include <string>
#include <unordered_map>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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

    const AssetType &get(const AssetId id) const
    {
        const auto found = mAssetMap.find(id);
        if (found == mAssetMap.end())
        {
            std::cerr << "Could not get asset\n";
            if (mAssetMap.empty())
            {
                /* No assets at all, we're sunk. */
                throw std::logic_error("No assets!");
            }

            /* Try to use a default asset. */
            return *mAssetMap.begin()->second;
        }

        return *found->second;
    }

private:
    std::unordered_map<AssetId, AssetType *> mAssetMap;
};

/* Convenience typedefs. */
typedef AssetManager<sf::Texture,     TextureId> TextureManager;
typedef AssetManager<sf::SoundBuffer, SoundId>   SoundManager;
