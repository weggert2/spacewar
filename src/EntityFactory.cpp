#include "EntityFactory.hpp"

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

void StartMenuCreator::create(entityx::Entity entity)
{
    auto menu = std::make_shared<StartMenu>(mTextManager, mFontManager);
    entity.assign<MenuComponent>(menu);

    const float x = Game::screenHeight/4.0;
    const float y = Game::screenHeight/10.0;
    entity.assign<Position>(sf::Vector2f(x,y), 0.0);

    // const std::string &splashText = mTextManager.get(TextId::Logo).get();

}
