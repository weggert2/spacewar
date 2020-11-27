#include "AssetLibrary.hpp"


namespace AssetLibrary
{

bool loadAllTextures(
    TextureManager &textureManager)
{
    bool success = true;

    success &= textureManager.load(TextureId::PlayerShip, "../assets/textures/blue/ship.png");

    return success;
}

bool loadAllSounds(
    SoundManager &soundManager)
{
    (void)soundManager;
    return true;
}

bool loadAllText(
    TextManager &textManager)
{
    bool success = true;

    success &= textManager.load(TextId::SplashScreen, "../assets/text/space_war.txt");

    return success;
}

} /* end namespace AssetLibrary. */
