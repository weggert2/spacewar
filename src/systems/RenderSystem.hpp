#pragma once

#include "AssetManager.hpp"

#include <entityx/System.h>
#include <SFML/Graphics.hpp>

class RenderSystem : public entityx::System<RenderSystem>
{
public:
    RenderSystem(
        sf::RenderWindow &window,
        const TextureManager &textureManager);

   void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);

private:
    sf::RenderWindow &mWindow;
    const TextureManager &mTextureManager;
};
