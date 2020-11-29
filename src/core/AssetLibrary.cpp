/**
 * @file
 *
 * $Id: AssetLibrary.cpp $
 * @author Bill Eggert
 */

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
    bool success = true;

    success &= soundManager.load(SoundId::PlayerShoot,  "../assets/sounds/mixkit-sci-fi-plasma-gun-power-up-1679.wav");
    success &= soundManager.load(SoundId::PlayerShoot2, "../assets/sounds/mixkit-laser-weapon-shot-1681.wav");
    success &= soundManager.load(SoundId::PlayerFly,    "../assets/sounds/mixkit-futuristic-robotic-fast-sweep-171.wav");
    success &= soundManager.load(SoundId::PlayerHit,    "../assets/sounds/mixkit-dramatic-metal-explosion-impact-1687.wav");
    success &= soundManager.load(SoundId::EnemyShoot,   "../assets/sounds/mixkit-laser-cannon-shot-1678.wav");
    success &= soundManager.load(SoundId::EnemyHit,     "../assets/sounds/mixkit-sea-mine-explosion-1184.wav");
    success &= soundManager.load(SoundId::Pause,        "../assets/sounds/mixkit-video-game-lock-2851.wav");
    success &= soundManager.load(SoundId::MenuScroll,   "../assets/sounds/mixkit-arcade-retro-changing-tab-206.wav");
    success &= soundManager.load(SoundId::MenuSelect,   "../assets/sounds/mixkit-sci-fi-positive-notification-266.wav");

    return success;
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

bool loadAllMusic(
    MusicManager &musicManager)
{
    bool success = true;

    success &= musicManager.load(MusicId::StartScreen, "../assets/music/Intergalactic-Odyssey.ogg");
    success &= musicManager.load(MusicId::Pause,       "../assets/music/Solve-The-Puzzle.ogg");
    success &= musicManager.load(MusicId::Playing,     "../assets/music/Interplanetary-Odyssey.ogg");
    success &= musicManager.load(MusicId::GameOver,    "../assets/music/Ruined-Planet.ogg");
    success &= musicManager.load(MusicId::Win,         "../assets/music/Chiptronical.ogg");

    return success;
}

} /* end namespace AssetLibrary. */
