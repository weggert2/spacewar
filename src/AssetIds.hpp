#pragma once

enum class TextureId
{
    Background,
    PlayerShip,
    EnemyShip,
    PlayerBullet,
    EnemyBullet
};

enum class SoundId
{
    PlayerShoot, // sci-fi-plasma-gun-powerup,
    PlayerShoot2, //laser-weapon-shot
    PlayerFly, // robotic-fast-sweep
    PlayerHit, // dramatic-metal-explosion

    EnemyShoot, // laser-cannon-shot
    EnemyHit, //sea-mine explosion

    Pause, // video-game-lock
    MenuScroll, //changing-tab
    MenuSelect, // positive-notification
};

enum class MusicId
{
    StartScreen, // alter-ego
    Playing,  //space-game
    GameOver, //own the night
    Winning, // time-heals
};

enum class TextId
{
    Logo,
    Pause,
    Controls,
    Credits,
    Win,
    GameOver,
};

enum class FontId
{
    Logo,
    Menu,
    Pause,
};
