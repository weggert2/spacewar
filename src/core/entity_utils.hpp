/**
 * @file
 *
 * $Id: enemy_utils.hpp $
 * @author Bill Eggert
 */

#pragma once

#include "components/Display.hpp"
#include "components/Player.hpp"
#include "components/Position.hpp"

#include <entityx/Entity.h>
#include <entityx/System.h>
#include <SFML/Graphics.hpp>

/*
 * This file defines some helpful methods for getting information about
 * common entities.
 */


/**
 * Get the position of the player from the entity manager.
 */
inline sf::Vector2f getPlayerPos(
    entityx::EntityManager &entityManager)
{
    Player::Handle player;
    Position::Handle position;

    for (entityx::Entity e : entityManager.entities_with_components(player, position))
    {
        (void)e;
        return position->getPos();
    }

    return sf::Vector2f();
}

/**
 * Get the axis-aligned bounds of the player from the entity manager.
 */
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
