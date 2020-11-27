#include "MenuSystem.hpp"

MenuSystem::MenuSystem(
    sf::RenderWindow &window,
    entityx::EntityManager &entityManager,
    entityx::EventManager &eventManager):
        mWindow(window),
        mEntityManager(entityManager),
        mEventManager(eventManager)
{
    subscribeEvents();
}

void MenuSystem::subscribeEvents()
{
    mEventManager.subscribe<KeyboardEvent>(*this);
}

void MenuSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    float dt)
{
    Menu::Handle menu;
    for (Entity e : entities.entities_with_components(menu))
    {

    }
}

