/**
 * @file
 *
 * $Id: AssedIds.hpp $
 * @author Bill Eggert
 */

#pragma once

/* The texture ids, to be used by a TextureManager */
enum class TextureId
{
    Background,
    PlayerShip,
    EnemyShip,
    PlayerBullet,
    EnemyBullet
};

/* The sound ids, to be used by a SoundManager. */
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

/* The music ids, to be used by a MusicManager */
enum class MusicId
{
    StartScreen, // Intergalactic Odyssey
    Pause, // Solve the Puzzle
    Playing, // Interplanetary Odyssey
    GameOver, // Ruined Planet
    Win, // Chiptronical
};

/* The text ids, to be used by a TextManager. */
enum class TextId
{
    Logo,
    Pause,
    Controls,
    Credits,
    Win,
    GameOver,
};

/* The font ids, to be used by a font manager. */
enum class FontId
{
    Logo,
    Menu,
    Pause,
};
