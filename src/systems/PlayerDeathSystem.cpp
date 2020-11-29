/**
 * @file
 *
 * $Id: PlayerDeathSystem.cpp $
 * @author Bill Eggert
 */

#include "PlayerDeathSystem.hpp"

#include "components/Player.hpp"
#include "Events.hpp"

void PlayerDeathSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    (void)dt;

    bool playerAlive = false;
    Player::Handle player;
    for (entityx::Entity e : entities.entities_with_components(player))
    {
        (void)e;
        playerAlive = true;
        break;
    }

    if (!playerAlive)
    {
        events.emit<LoseGameEvent>();
    }
}
