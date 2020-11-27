#pragma once

#include <entityx/Event.h>
#include <SFML/Graphics.hpp>

/*
 * Base class for menus.
 */

class MenuBase
{
public:
    virtual ~MenuBase() = default;

    virtual void update(entityx::EventManager &events, float dt) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual void select(entityx::EventManager &eventManager) = 0;
    virtual void cancel(entityx::EventManager &eventManager) = 0;
    virtual void up(entityx::EventManager &eventManager) = 0;
    virtual void down(entityx::EventManager &eventManager) = 0;
    virtual void left(entityx::EventManager &eventManager) = 0;
    virtual void right(entityx::EventManager &eventManager) = 0;
};
