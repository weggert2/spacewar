#include "EntityFactory.hpp"

#include "components/Display.hpp"
#include "components/MenuComponent.hpp"
#include "components/StartMenu.hpp"
#include "components/Position.hpp"
#include "Game.hpp"

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
    entity.assign<Display>(mTextureManager.get(TextureId::Background));
    entity.assign<Position>(sf::Vector2f(), 0.0);
}
