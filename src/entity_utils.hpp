#pragma once

#include "components/Display.hpp"
#include "components/Player.hpp"
#include "components/Position.hpp"

#include <entityx/Entity.h>
#include <entityx/System.h>
#include <SFML/Graphics.hpp>


inline sf::Vector2f getPlayerPos(
    entityx::EntityManager &entityManager)
{
    Player::Handle player;
    Position::Handle position;

    for (entityx::Entity e : entityManager.entities_with_components(player, position))
    {
        (void)e;
        return position->getX();
    }

    return sf::Vector2f();
}

inline sf::FloatRect getPlayerBounds(
    entityx::EntityManager &entityManager)
{
    Player::Handle player;
    Display::Handle display;

    for (entityx::Entity e : entityManager.entities_with_components(player, display))
    {
        (void)e;
        return display->mSprite.getGlobalBounds();
    }

    return sf::FloatRect();
}
