/**
 * @file
 *
 * $Id: MenuSystem.hpp $
 * @author Bill Eggert
 */

#pragma once

#include "Events.hpp"

#include <entityx/System.h>
#include <SFML/Graphics.hpp>

/* Multiple inheritance, watch out! */

/*
 * The system for handling menu interaction.
 */

class MenuSystem : public entityx::System<MenuSystem>,
                   public entityx::Receiver<MenuSystem>
{
public:
    MenuSystem(
        sf::RenderWindow &window,
        entityx::EntityManager &entityManager,
        entityx::EventManager &eventManager);

    void subscribeEvents();

    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        double dt);

    void receive(
        const KeyboardEvent &event);

private:
    sf::RenderWindow &mWindow;
    entityx::EntityManager &mEntityManager;
    entityx::EventManager &mEventManager;
};
