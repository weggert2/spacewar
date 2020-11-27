#pragma once

#include "MenuBase.hpp"

class StartMenu : public MenuBase
{
public:
    virtual void update(entityx::EventManager &events, float dt) override final;
    virtual void draw(sf::RenderWindow &window) override final;
    virtual void select(entityx::EventManager &eventManager) override final {}
    virtual void cancel(entityx::EventManager &eventManager) override final {}
    virtual void up(entityx::EventManager &eventManager) override final {}
    virtual void down(entityx::EventManager &eventManager) override final {}
    virtual void left(entityx::EventManager &eventManager) override final {}
    virtual void right(entityx::EventManager &eventManager) override final {}

private:
};
