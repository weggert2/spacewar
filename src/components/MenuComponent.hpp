#pragma once

#include <entityx/Entity.h>
#include <entityx/Event.h>
#include <SFML/Graphics.hpp>

class MenuBase;

class MenuComponent : public entityx::Component<MenuComponent>
{
public:
    explicit MenuComponent(
        MenuBase *menu);

    void update(entityx::EventManager &events, const float dt);
    void draw(sf::RenderWindow &window);
    void select(entityx::EventManager &eventManager);
    void cancel(entityx::EventManager &eventManager);
    void up(entityx::EventManager &eventManager);
    void down(entityx::EventManager &eventManager);
    void left(entityx::EventManager &eventManager);
    void right(entityx::EventManager &eventManager);

private:
    MenuBase *mMenu;
};
