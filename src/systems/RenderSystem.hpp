#pragma once

#include <entityx/System.h>
#include <SFML/Graphics.hpp>

class RenderSystem : public entityx::System<RenderSystem>
{
public:
    RenderSystem(
        sf::RenderWindow &window,
        TextureManager &textureManager);

   void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);

private:
    sf::RenderWindow &mWindow;
    TextureManager &mTextureManager;
};
