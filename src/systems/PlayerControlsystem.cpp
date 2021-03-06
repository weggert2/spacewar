/**
 * @file
 *
 * $Id: PlayerControlSystem.cpp $
 * @author Bill Eggert
 */

#include "PlayerControlSystem.hpp"

#include "KeyManager.hpp"

#include "components/PlayerControl.hpp"
#include "components/Motion.hpp"
#include "components/Weapon.hpp"

PlayerControlSystem::PlayerControlSystem(
    const KeyManager &keyManager):
        mKeyManager(keyManager)
{
}

void PlayerControlSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    (void)events;
    (void)dt;

    PlayerControl::Handle playerControl;
    Motion::Handle motion;
    Weapon::Handle weapon;

    for (entityx::Entity e : entities.entities_with_components(playerControl, motion, weapon))
    {
        (void)e;

        motion->setImpulse(
            mKeyManager.isPressed(playerControl->getBindUp()),
            mKeyManager.isPressed(playerControl->getBindDown()));

        motion->setRotate(
            mKeyManager.isPressed(playerControl->getBindLeft()),
            mKeyManager.isPressed(playerControl->getBindRight()));

        weapon->setActive(mKeyManager.isPressed(playerControl->getBindShoot()));
    }
}
