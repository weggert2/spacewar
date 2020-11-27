#include "EntityFactory.hpp"

#include "Game.hpp"

#include "components/Background.hpp"
#include "components/Display.hpp"
#include "components/MenuComponent.hpp"
#include "components/Motion.hpp"
#include "components/Position.hpp"
#include "components/Player.hpp"
#include "components/PlayerControl.hpp"
#include "components/StartMenu.hpp"

StartMenuCreator::StartMenuCreator(
    const TextManager &textManager,
    const FontManager &fontManager):
        mTextManager(textManager),
        mFontManager(fontManager)
{
}

void StartMenuCreator::create(
    entityx::Entity entity)
{
    auto menu = std::make_shared<StartMenu>(mTextManager, mFontManager);
    entity.assign<MenuComponent>(menu);

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
    // entity.assign<Weapon>();

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
