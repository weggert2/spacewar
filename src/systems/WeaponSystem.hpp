#pragma once

#include "AssetManager.hpp"

#include <entityx/System.h>

class WeaponSystem : public entityx::System<WeaponSystem>
{
public:
    explicit WeaponSystem(
        const TextureManager &textureManager);

    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);

private:
    const TextureManager &mTextureManager;
};
