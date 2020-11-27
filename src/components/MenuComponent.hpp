#pragma once

#include <entityx/Entity.h>
#include <entityx/Event.h>
#include <SFML/Graphics.hpp>

#include <memory>

class MenuBase;

class MenuComponent : public entityx::Component<MenuComponent>
{
public:
    explicit MenuComponent(
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
