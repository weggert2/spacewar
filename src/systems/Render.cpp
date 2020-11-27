#include "Render.hpp"

#include "components/Background.hpp"
#include "components/Display.hpp"
#include "components/Position.hpp"

Render::Render(
    sf::RenderWindow &window,
    const TextureManager &textureManager):
        mWindow(window),
        mTextureManager(textureManager)
{
}

void Render::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    mWindow.clear();

    Position::Handle position;
    Background::Handle background;
    for (entityx::Entity e : entities.entities_with_components(position, background))
    {
        background->mSprite.setPosition(position->getX());
        mWindow.draw(background->mSprite);
    }

    Display::Handle display;
    for (entityx::Entity e : entities.entities_with_components(position, display))
    {
        display->mSprite.setPosition(position->getX());
        display->mSprite.setRotation(position->getTheta());
        mWindow.draw(display->mSprite);
    }
}
