/**
 * @file
 *
 * $Id: EntityFactory.cpp $
 * @author Bill Eggert
 */

#include "EntityFactory.hpp"

#include "Game.hpp"
#include "GameManager.hpp"

#include "components/Background.hpp"
#include "components/Display.hpp"
#include "components/Enemy.hpp"
#include "components/EnemyControl.hpp"
#include "components/Hitbox.hpp"
#include "components/Menu.hpp"
#include "components/Motion.hpp"
#include "components/Position.hpp"
#include "components/Player.hpp"
#include "components/PlayerControl.hpp"
#include "components/Projectile.hpp"
#include "components/StartMenu.hpp"
#include "components/Weapon.hpp"

StartMenuCreator::StartMenuCreator(
    const std::wstring &logoText,
    const sf::Font &logoFont,
    const sf::Font &menuFont,
    const GameManager &gameManager,
    const int logoFontSize):
        mLogoText(logoText),
        mLogoFont(logoFont),
        mMenuFont(menuFont),
        mGameManager(gameManager),
        mLogoFontSize(logoFontSize)
{
}

void StartMenuCreator::create(
    entityx::Entity entity)
{
    auto menu = std::make_shared<StartMenu>(
        mLogoText,
        mLogoFont,
        mMenuFont,
        mGameManager,
        mLogoFontSize);

    entity.assign<Menu>(menu);

    const float x = Game::screenWidth/2.0f;
    const float y = Game::screenHeight/2.5f;
    entity.assign<Position>(sf::Vector2f(x,y), 0.0f);
}

BackgroundCreator::BackgroundCreator(
    const TextureManager &textureManager):
        mTextureManager(textureManager)
{
}

void BackgroundCreator::create(
    entityx::Entity entity)
{
    entity.assign<Background>(mTextureManager.get(TextureId::Background));
    entity.assign<Position>(sf::Vector2f(), 0.0f);
}

PlayerCreator::PlayerCreator(
    const TextureManager &textureManager):
        mTextureManager(textureManager)
{
}

void PlayerCreator::create(
    entityx::Entity entity)
{
    /* Get the sprite bounds to determine the hitbox. */
    const sf::Texture &texture = mTextureManager.get(TextureId::PlayerShip);
    const sf::FloatRect bounds = Display(texture).mSprite.getGlobalBounds();

    entity.assign<Display>(texture);
    // entity.assign<Health>();
    entity.assign<Hitbox>(bounds.width, bounds.height);
    entity.assign<Motion>();
    entity.assign<Player>();
    entity.assign<PlayerControl>();
    entity.assign<Weapon>();

    /* Start the player in the lower right of the screen. */
    auto pos = 0.8f*sf::Vector2f(Game::screenWidth, Game::screenHeight);
    entity.assign<Position>(pos, 0.0f);
}

EnemyCreator::EnemyCreator(
    const TextureManager &textureManager,
    const sf::Vector2f &initialPos,
    const float initialAngle):
        mTextureManager(textureManager),
        mInitialPos(initialPos),
        mInitialAngle(initialAngle)
{
}

void EnemyCreator::create(
    entityx::Entity entity)
{
    /* Get the sprite bounds to determine the hitbox. */
    const sf::Texture &texture = mTextureManager.get(TextureId::EnemyShip);
    const sf::FloatRect bounds = Display(texture).mSprite.getGlobalBounds();

    entity.assign<Display>(texture);
    entity.assign<Enemy>();
    entity.assign<EnemyControl>();
    // entity.assign<Health>();
    entity.assign<EnemyControl>();
    entity.assign<Hitbox>(bounds.width, bounds.height);
    entity.assign<Motion>();
    entity.assign<Position>(mInitialPos, mInitialAngle);
    entity.assign<Weapon>();
}

ProjectileCreator::ProjectileCreator(
    const TextureManager &textureManager,
    const TextureInfo &textureInfo,
    const sf::Vector2f &initialPos,
    const float initialAngle):
        mTextureManager(textureManager),
        mTextureInfo(textureInfo),
        mInitialPos(initialPos),
        mInitialAngle(initialAngle)
{
}

void ProjectileCreator::create(
    entityx::Entity entity)
{
    /* Get the sprite bounds to determine the hitbox. */
    const sf::Texture &texture = mTextureManager.get(mTextureInfo.mTextureId);
    const Display display(
        texture,
        mTextureInfo.mScaleY,
        mTextureInfo.mOrigX,
        mTextureInfo.mOrigY);

    const sf::FloatRect bounds = display.mSprite.getGlobalBounds();
    entity.assign_from_copy<Display>(display);

    const float speed = -450.0f; /* Negative? Ok I guess. */
    const float omega = 0.0f;

    entity.assign<Motion>(speed, omega, speed, omega);
    entity.assign<Position>(mInitialPos, mInitialAngle);
    entity.assign<Hitbox>(bounds.width, bounds.height);
    entity.assign<Projectile>();
}
