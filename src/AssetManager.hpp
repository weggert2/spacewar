#pragma once

#include <unordered_map>

template <typename Asset, typename Identifier>
class AssetManager
{
public:
    ~AssetManager()
    {
        for (auto &assetPair : mAssetMap)
        {
            delete assetPair.second;
        }
    }

    bool load(
        const Identifier id,
        const std::string &filename)
    {
        Asset *asset = new Asset();
        if (!asset->loadFromFile(filename))
        {
            return false;
        }

        mAssetMap[id] = asset;
        return true;
    }

    bool get(
        const Identifier id,
        Asset &asset) const
    {
        const auto found = mAssetMap.find(id);
        if (found == mAssetMap.end())
        {
            return false;
        }

        asset = *found->second;
        return true;
    }

private:
    std::unordered_map<Identifier, Asset *> mAssetMap;
};
