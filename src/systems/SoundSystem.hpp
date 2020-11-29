#pragma once

#include "AssetManager.hpp"

#include "Events.hpps"

#include <entityx/System.h>
#include <SFML/Graphics.hpp>

class SoundSystem : public entityx::System<SoundSystem>
{
public:
    explicit SoundSystem(
        const SoundManager &soundManager,
        entityx::EventManager &eventManager);

   void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);

   void receive(const PlaySoundEvent &event);

private:
    SoundManager &mSoundManager;
};
