#include "PlayerControlSystem.hpp"

#include "KeyManager.hpp"

PlayerControlSystem::PlayerControlSystem(
    const KeyManager &keyManager):
        mKeyManager(keyManager)
{
}
