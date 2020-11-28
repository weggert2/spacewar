#pragma once

#include "AssetManager.hpp"
#include "Events.hpp"

#include <entityx/System.h>
#include <SFML/System/Vector2.hpp>

class StageSystem : public entityx::System<StageSystem>,
                    public entityx::Receiver<StageSystem>
{
public:
    StageSystem(
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
    void receive(const WinGameEvent &event);
    void receive(const LoseGameEvent &event);

private:
    bool validEnemyPos(
        const sf::Vector2f &pos,
        const std::vector<sf::Vector2f> &placed,
        const float threshold) const;

private:
    const TextureManager &mTextureManager;
    entityx::EntityManager &mEntityManager;
    entityx::EventManager &mEventManager;

    /* What stage the player is currently on. Every time all the enemies on
     * a stage are killed, the stage increases and more enemies are added. */
    size_t mStage;

    const size_t winStage = 10u;
};
