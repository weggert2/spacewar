#include "MenuSystem.hpp"

#include "components/MenuComponent.hpp"
#include "components/Position.hpp"

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
    MenuComponent::Handle menu;
    Position::Handle position;
    for (entityx::Entity e : entities.entities_with_components(menu, position))
    {
        menu->update(events, dt);
        menu->draw(mWindow, position->getX());
    }
}

void MenuSystem::receive(
    const KeyboardEvent &event)
{
    if (!event.getPressed())
    {
        return;
    }

    MenuComponent::Handle menu;
    for (entityx::Entity e : mEntityManager.entities_with_components(menu))
    {
        switch (event.getKey())
        {
            case sf::Keyboard::Up:    menu->up(mEventManager);    break;
            case sf::Keyboard::Down:  menu->down(mEventManager);  break;
            case sf::Keyboard::Left:  menu->left(mEventManager);  break;
            case sf::Keyboard::Right: menu->right(mEventManager); break;
            default: break;
        }
    }
}

