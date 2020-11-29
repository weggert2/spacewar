/**
 * @file
 *
 * $Id: RenderSystem.cpp $
 * @author Bill Eggert
 */

#include "RenderSystem.hpp"

#include "components/Background.hpp"
#include "components/Display.hpp"
#include "components/Position.hpp"

RenderSystem::RenderSystem(
    sf::RenderWindow &window,
    const TextureManager &textureManager):
        mWindow(window),
        mTextureManager(textureManager)
{
}

void RenderSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    (void)events;
    (void)dt;

    mWindow.clear();

    Position::Handle position;
    Background::Handle background;
    for (entityx::Entity e : entities.entities_with_components(position, background))
    {
        (void)e;

        background->mSprite.setPosition(position->getPos());
        mWindow.draw(background->mSprite);
    }

    Display::Handle display;
    for (entityx::Entity e : entities.entities_with_components(position, display))
    {
        (void)e;

        display->mSprite.setPosition(position->getPos());
        display->mSprite.setRotation(position->getTheta());
        mWindow.draw(display->mSprite);
    }
}
