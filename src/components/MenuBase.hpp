/**
 * @file
 *
 * $Id: MenuBase.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <entityx/Event.h>
#include <SFML/Graphics.hpp>

/*
 * Base class for menus. These are the actual things that do the work.
 * The "Menu" class is the component.
 */

class MenuBase
{
public:
    virtual ~MenuBase() = default;

    virtual void update(entityx::EventManager &events, float dt) = 0;
    virtual void draw(sf::RenderWindow &window, const sf::Vector2f &pos) = 0;
    virtual void select(entityx::EventManager &eventManager) = 0;
    virtual void cancel(entityx::EventManager &eventManager) = 0;
    virtual void up(entityx::EventManager &eventManager) = 0;
    virtual void down(entityx::EventManager &eventManager) = 0;
    virtual void left(entityx::EventManager &eventManager) = 0;
    virtual void right(entityx::EventManager &eventManager) = 0;
};
