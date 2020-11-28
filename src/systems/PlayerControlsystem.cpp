#include "PlayerControlSystem.hpp"

#include "KeyManager.hpp"

#include "components/PlayerControl.hpp"
#include "components/Motion.hpp"

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

    for (entityx::Entity e : entities.entities_with_components(playerControl, motion))
    {
        (void)e;

        motion->setImpulse(
            mKeyManager.isPressed(playerControl->getBindUp()),
            mKeyManager.isPressed(playerControl->getBindDown()));

        motion->setRotate(
            mKeyManager.isPressed(playerControl->getBindLeft()),
            mKeyManager.isPressed(playerControl->getBindRight()));
    }
}
