#include "AssetLibrary.hpp"


namespace AssetLibrary
{

bool loadAllTextures(
    TextureManager &textureManager)
{
    bool success = true;

    success &= textureManager.load(TextureId::PlayerShip,   "../assets/textures/blue/ship.png");
    success &= textureManager.load(TextureId::PlayerBullet, "../assets/textures/blue/bullet.png");
    success &= textureManager.load(TextureId::EnemyShip,    "../assets/textures/red/spaceship_enemy_red.png");
    success &= textureManager.load(TextureId::EnemyBullet,  "../assets/textures/red/bullet_red.png");
    success &= textureManager.load(TextureId::Background,   "../assets/textures/background/black_hole6.jpg");

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

    success &= textManager.load(TextId::Logo,     "../assets/text/space_war.txt");
    success &= textManager.load(TextId::Pause,    "../assets/text/pause.txt");
    success &= textManager.load(TextId::GameOver, "../assets/text/game_over.txt");
    success &= textManager.load(TextId::Controls, "../assets/text/controls.txt");
    success &= textManager.load(TextId::Credits,  "../assets/text/credits.txt");
    success &= textManager.load(TextId::Win,      "../assets/text/win.txt");

    return success;
}

bool loadAllFonts(
    FontManager &fontManager)
{
    bool success = true;

    success &= fontManager.load(FontId::Logo,  "../assets/fonts/RobotoMono-Regular.ttf");
    success &= fontManager.load(FontId::Menu,  "../assets/fonts/galiver-sans.ttf");
    success &= fontManager.load(FontId::Pause, "../assets/fonts/Monospace.ttf");

    return success;
}

} /* end namespace AssetLibrary. */
