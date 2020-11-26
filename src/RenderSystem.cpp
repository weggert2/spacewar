#include "RenderSystem.hpp"

RenderSystem::RenderSystem(
    sf::RenderWindow &window,
    TextureManager &textureManager):
        mWindow(window),
        mTextureManager(textureManager)
{
}

void RenderSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    mWindow.clear();
}
