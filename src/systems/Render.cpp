#include "Render.hpp"

#include "AssetManager.hpp"

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
    Display::Handle display;

    for (Entity e : entities.entities_with_component(position, display))
    {
        display.mSprite.setPosition(position.getX());
        display.mSprite.setRotation(position.getTheta());
        mWindow.draw(display.mSprite);
    }
}
