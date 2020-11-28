#include "PlayerControlSystem.hpp"

#include "KeyManager.hpp"

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
    std::cout << "Got here" << std::endl;
}
