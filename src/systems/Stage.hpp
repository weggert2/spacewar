#pragma once

#include "AssetManager.hpp"

#include <entityx/System.h>

class Stage : public entityx::System<Stage>,
              public entityx::Receiver<Stage>
{
public:
    Stage(
        const TextureManager &textureManager,
        entityx::EntityManager &entityManager,
        entityx::EventManager &eventManager);

    void subscribeEvents();

    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);

    void receive(const StartGameEvent &event);
    void receive(const StageClearedEvent &event);

private:
    const TextureManager &mTextureManager;
    entityx::EntityManager &mEntityManager;
    entityx::EventManager &mEventManager;

    /* What stage the player is currently on. Every time all the enemies on
     * a stage are killed, the stage increases and more enemies are added. */
    size_t mStage;
};
