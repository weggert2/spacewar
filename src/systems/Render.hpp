#pragma once

#include <entityx/System.h>
#include <SFML/Graphics.hpp>

class Render : public entityx::System<Render>
{
public:
    Render(
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
