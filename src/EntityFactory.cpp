#include "EntityFactory.hpp"

#include "Game.hpp"
#include "GameManager.hpp"

#include "components/Background.hpp"
#include "components/Display.hpp"
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
    const GameManager &gameManager):
        mLogoText(logoText),
        mLogoFont(logoFont),
        mMenuFont(menuFont),
        mGameManager(gameManager)
{
}

void StartMenuCreator::create(
    entityx::Entity entity)
{
    auto menu = std::make_shared<StartMenu>(
        mLogoText,
        mLogoFont,
        mMenuFont,
        mGameManager);

    entity.assign<Menu>(menu);

    const float x = Game::screenWidth/2.0;
    const float y = Game::screenHeight/2.5;
    entity.assign<Position>(sf::Vector2f(x,y), 0.0);
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
    entity.assign<Position>(sf::Vector2f(), 0.0);
}

PlayerCreator::PlayerCreator(
    const TextureManager &textureManager):
        mTextureManager(textureManager)
{
}

void PlayerCreator::create(
    entityx::Entity entity)
{
    entity.assign<Display>(mTextureManager.get(TextureId::PlayerShip));
    // entity.assign<Health>();
    // entity.assign<Hitbox>();
    entity.assign<Motion>();
    entity.assign<Player>();
    entity.assign<PlayerControl>();
    entity.assign<Weapon>();

    /* Start the player in the lower right of the screen. */
    auto pos = 0.8f*sf::Vector2f(Game::screenWidth, Game::screenHeight);
    entity.assign<Position>(pos, 0.0);
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
    // entity.assign<Control>();
    entity.assign<Display>(mTextureManager.get(TextureId::EnemyShip));
    // entity.assign<Health>();
    // entity.assign<Hitbox>();
    // entity.assign<Motion>();
    entity.assign<Position>(mInitialPos, mInitialAngle);
    // entity.assign<Weapon>();
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
    entity.assign<Display>(
        mTextureManager.get(mTextureInfo.mTextureId),
        mTextureInfo.mScaleX,
        mTextureInfo.mScaleY,
        mTextureInfo.mOrigX,
        mTextureInfo.mOrigY);

    const float bulletSpeed = -450.0f;
    const float bulletOmega = 0.0;

    entity.assign<Motion>(bulletSpeed, bulletOmega, bulletSpeed, bulletOmega);
    entity.assign<Position>(mInitialPos, mInitialAngle);
    entity.assign<Projectile>();
}
