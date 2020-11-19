#include "AssetLibrary.hpp"


namespace AssetLibrary
{

bool loadAllTextures(TextureManager &textureManager)
{
    bool success = true;

    success &= textureManager.load(TextureId::PlayerShip, "../assets/textures/blue/ship.png");

    return success;
}

bool loadAllSounds(SoundManager &soundManager)
{
    (void)soundManager;
    return true;
}

} /* end namespace AssetLibrary. */
