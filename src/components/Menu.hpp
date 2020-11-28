#pragma once

#include <entityx/Entity.h>
#include <entityx/Event.h>
#include <SFML/Graphics.hpp>

#include <memory>

class MenuBase;

/*
 * Menu is the component. MenuBase and the things that inherit it provide
 * the menu logic.
 */

class Menu : public entityx::Component<Menu>
{
public:
    explicit Menu(
        std::shared_ptr<MenuBase> menu);

    void update(entityx::EventManager &events, const float dt);
    void draw(sf::RenderWindow &window, const sf::Vector2f &pos);
    void select(entityx::EventManager &eventManager);
    void cancel(entityx::EventManager &eventManager);
    void up(entityx::EventManager &eventManager);
    void down(entityx::EventManager &eventManager);
    void left(entityx::EventManager &eventManager);
    void right(entityx::EventManager &eventManager);

private:
    std::shared_ptr<MenuBase> mMenu;
};
