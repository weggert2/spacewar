#include "MenuComponent.hpp"

#include "MenuBase.hpp"

MenuComponent::MenuComponent(
    std::shared_ptr<MenuBase> menu):
        mMenu(menu)
{
}

void MenuComponent::update(
    entityx::EventManager &events,
    const float dt)
{
    mMenu->update(events, dt);
}

void MenuComponent::draw(
    sf::RenderWindow &window,
    const sf::Vector2f &pos)
{
    mMenu->draw(window, pos);
}

void MenuComponent::select(
    entityx::EventManager &eventManager)
{
    mMenu->select(eventManager);
}

void MenuComponent::cancel(
    entityx::EventManager &eventManager)
{
    mMenu->cancel(eventManager);
}

void MenuComponent::up(
    entityx::EventManager &eventManager)
{
    mMenu->up(eventManager);
}

void MenuComponent::down(
    entityx::EventManager &eventManager)
{
    mMenu->down(eventManager);
}

void MenuComponent::left(
    entityx::EventManager &eventManager)
{
    mMenu->left(eventManager);
}

void MenuComponent::right(
    entityx::EventManager &eventManager)
{
    mMenu->right(eventManager);
}
