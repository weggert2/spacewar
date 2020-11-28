#include "Menu.hpp"

#include "MenuBase.hpp"

Menu::Menu(
    std::shared_ptr<MenuBase> menu):
        mMenu(menu)
{
}

void Menu::update(
    entityx::EventManager &events,
    const float dt)
{
    mMenu->update(events, dt);
}

void Menu::draw(
    sf::RenderWindow &window,
    const sf::Vector2f &pos)
{
    mMenu->draw(window, pos);
}

void Menu::select(
    entityx::EventManager &eventManager)
{
    mMenu->select(eventManager);
}

void Menu::cancel(
    entityx::EventManager &eventManager)
{
    mMenu->cancel(eventManager);
}

void Menu::up(
    entityx::EventManager &eventManager)
{
    mMenu->up(eventManager);
}

void Menu::down(
    entityx::EventManager &eventManager)
{
    mMenu->down(eventManager);
}

void Menu::left(
    entityx::EventManager &eventManager)
{
    mMenu->left(eventManager);
}

void Menu::right(
    entityx::EventManager &eventManager)
{
    mMenu->right(eventManager);
}
