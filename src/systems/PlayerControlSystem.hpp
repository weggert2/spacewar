#pragma once

#include <entityx/System.h>
#include <SFML/System/Vector2.hpp>

class KeyManager;

class PlayerControlSystem : public entityx::System<PlayerControlSystem>
{
public:
    PlayerControlSystem(
        const KeyManager &keyManager);

    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);

private:
    const KeyManager &mKeyManager;
};
