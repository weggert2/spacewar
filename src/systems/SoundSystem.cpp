#include "SoundSystem.hpp"

SoundSystem::SoundSystem(
    const SoundManager &soundManager,
    entityx::EventManager &eventManager):
        mSoundManager(soundManager)
{
    eventManager.subscribe<PlaySoundEvent>(*this);
}

void SoundSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    /* Nothing needed */
    (void)entities;
    (void)events;
    (void)dt;
}

void SoundSystem::receive(
    const PlaySoundEvent &soundEvent)
