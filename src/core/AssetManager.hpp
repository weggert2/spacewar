/**
 * @file
 *
 * $Id: AssetManager.hpp $
 * @author Bill Eggert
 */

#pragma once

#include "AssetIds.hpp"
#include "MusicWrapper.hpp"
#include "StringWrapper.hpp"

#include <iostream>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/**
 * An AssetManager serves as storage for the games assets. When other
 * game elements use an asset manager, they do not have to worry about the
 * lifetime of the assets.
 *
 * An AssetManager stores assets as a map of Id to asset ptr. The AssetManager
 * class is a pseudo-base class. Users will want to use one of the typedefs
 * defined at the bottom of this file.
 *
 * @tparam AssetType The type of asset. For example, sf::Texture
 * @tparam The AssetId type. For example, SoundId.
 */
template <typename AssetType, typename AssetId>
class AssetManager
{
public:
    /* Clean up the memory used by the assets. */
    ~AssetManager()
    {
        /* Prefer raw pointers to std::unique_ptr for performance. */
        for (auto &assetPair : mAssetMap)
        {
            delete assetPair.second;
        }
    }

    /**
     * Load an asset by filename, assigning it to the asset id in the map.
     */
    bool load(
        const AssetId id,
        const std::string &filename)
    {
        AssetType *asset = new AssetType();
        if (!asset->loadFromFile(filename))
        {
            /* SFML will already print to cerr, so we don't have to. */
            return false;
        }

        mAssetMap[id] = asset;
        return true;
    }

    /**
     * Get a const ref to an asset by id.
     */
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

    /**
     * Get a ref to an asset by id.
     */
    AssetType &get(const AssetId id)
    {
        auto found = mAssetMap.find(id);
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
    /** The asset storage. */
    std::map<AssetId, AssetType *> mAssetMap;
};

/* Convenience typedefs. */
typedef AssetManager<sf::Texture,     TextureId> TextureManager;
typedef AssetManager<sf::SoundBuffer, SoundId>   SoundManager;
typedef AssetManager<sf::Font,        FontId>    FontManager;
typedef AssetManager<StringWrapper,   TextId>    TextManager;
typedef AssetManager<MusicWrapper,    MusicId>   MusicManager;
