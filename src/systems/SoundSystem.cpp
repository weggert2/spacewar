/**
 * @file
 *
 * $Id: SoundSystem.cpp $
 * @author Bill Eggert
 */

#include "SoundSystem.hpp"

#include "components/Player.hpp"
#include "components/Position.hpp"

/* These numbers taken from the SFML textbook. */
static constexpr float Attenuation = 8.0f;
static constexpr float ListenerZ = 300.0f;
static constexpr float MinDistance2D = 200.0f;
static const float MinDistance3D = std::sqrt(
    MinDistance2D*MinDistance2D + ListenerZ*ListenerZ);

SoundSystem::SoundSystem(
    const SoundManager &soundManager,
    entityx::EventManager &eventManager):
        mSoundManager(soundManager),
        mActiveSounds()
{
    eventManager.subscribe<PlaySoundEvent>(*this);
}

void SoundSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    (void)events;
    (void)dt;

    Player::Handle player;
    Position::Handle position;
    for (entityx::Entity e : entities.entities_with_components(player, position))
    {
        (void)e;
        setListenerPosition(position->getPos());
    }

    removeStoppedSounds();
}

void SoundSystem::receive(
    const PlaySoundEvent &soundEvent)
{
    const SoundId soundId = soundEvent.get();
    const sf::Vector2f position = getListenerPosition();

    mActiveSounds.push_back(sf::Sound());
    sf::Sound &sound = mActiveSounds.back();
    sound.setBuffer(mSoundManager.get(soundId));

    sound.setPosition(position.x, -position.y, 00.f);
    sound.setAttenuation(Attenuation);
    sound.setMinDistance(MinDistance3D);

    #ifndef NO_SOUND
    /* No sounds while debugging. */
    sound.play();
    #endif
}

void SoundSystem::removeStoppedSounds()
{
    mActiveSounds.remove_if([] (const sf::Sound &s) {
        return s.getStatus() == sf::Sound::Stopped;
    });
}

sf::Vector2f SoundSystem::getListenerPosition() const
{
    sf::Vector3f position = sf::Listener::getPosition();
    return sf::Vector2f(position.x, -position.y);
}

void SoundSystem::setListenerPosition(
    const sf::Vector2f &position)
{
    sf::Listener::setPosition(position.x, -position.y, ListenerZ);
}
