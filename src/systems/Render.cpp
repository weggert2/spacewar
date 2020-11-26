#include "Render.hpp"

Render::Render(
    sf::RenderWindow &window,
    TextureManager &textureManager):
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
}
