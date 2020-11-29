/**
 * @file
 *
 * $Id: SoundSystem.hpp $
 * @author Bill Eggert
 */

#pragma once

#include "AssetManager.hpp"

#include "Events.hpp"

#include <entityx/System.h>
#include <SFML/Graphics.hpp>

#include <algorithm>
#include <cmath>
#include <list>

class SoundSystem : public entityx::System<SoundSystem>,
                    public entityx::Receiver<SoundSystem>
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
    void removeStoppedSounds();

    sf::Vector2f getListenerPosition() const;

    void setListenerPosition(
        const sf::Vector2f &position);

private:
    const SoundManager &mSoundManager;
    std::list<sf::Sound> mActiveSounds;

    /* These numbers taken from the SFML textbook. */
    static constexpr float Attenuation = 8.0f;
    static constexpr float ListenerZ = 300.0f;
    static constexpr float MinDistance2D = 200.0f;
    inline static float MinDistance3D = std::sqrt(
        MinDistance2D*MinDistance2D + ListenerZ*ListenerZ);
};
