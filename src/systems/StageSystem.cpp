/**
 * @file
 *
 * $Id: StageSystem.cpp $
 * @author Bill Eggert
 */

#include "StageSystem.hpp"

#include "components/Display.hpp"
#include "components/Position.hpp"
#include "components/Player.hpp"
#include "components/Enemy.hpp"

#include "Game.hpp"
#include "EntityFactory.hpp"
#include "entity_utils.hpp"
#include "math_utils.hpp"

#include <random>

StageSystem::StageSystem(
    const TextureManager &textureManager,
    entityx::EntityManager &entityManager,
    entityx::EventManager &eventManager):
        mTextureManager(textureManager),
        mEntityManager(entityManager),
        mEventManager(eventManager),
        mStage(0u)
{
    subscribeEvents();
}

void StageSystem::subscribeEvents()
{
    mEventManager.subscribe<StartGameEvent>(*this);
    mEventManager.subscribe<StageClearedEvent>(*this);
    mEventManager.subscribe<WinGameEvent>(*this);
    mEventManager.subscribe<LoseGameEvent>(*this);
}

void StageSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    (void)dt;

    /* If there are no enemies, clear the stage. */
    bool enemiesRemain = false;
    Enemy::Handle enemy;
    for (entityx::Entity e : entities.entities_with_components(enemy))
    {
        (void)e;
        enemiesRemain = true;
        break;
    }

    if (!enemiesRemain)
    {
        events.emit<StageClearedEvent>();
    }
}

void StageSystem::receive(
    const StartGameEvent &event)
{
    (void)event;

    /* Destroy any existing players (e.g. if we've won the game) */
    mEntityManager.each<Player>([](entityx::Entity e, Player&) {
        e.destroy();
    });

    /* Make the background, player, and the black hole. */
    BackgroundCreator(mTextureManager).create(mEntityManager.create());
    PlayerCreator(mTextureManager).create(mEntityManager.create());
    BlackHoleCreator().create(mEntityManager.create());

    /* Clear the zero'th stage. */
    mEventManager.emit<StageClearedEvent>();
}

void StageSystem::receive(
    const StageClearedEvent &event)
{
    (void)event;

    mStage++;
    if (mStage >= winStage)
    {
        mEventManager.emit<WinGameEvent>();
        return;
    }

    /*
     * We want to place mStage enemies such that they are:
     *  - within the screen bounds
     *  - further than a certain distance from the player
     *  - further than a certain distance from the black hole
     *
     * We'll be kind of dumb about it - we'll generate random positions and
     * then check the criteria. After maxiters, just give up on placing that
     * enemy.
     */

    const sf::Vector2f playerPos = getPlayerPos(mEntityManager);
    const sf::FloatRect playerBounds = getPlayerBounds(mEntityManager);
    const float edgeOffset = playerBounds.width/2.0f;
    const float playerOffset = 5.0f*edgeOffset*edgeOffset;

    std::vector<sf::Vector2f> placed;
    placed.push_back(playerPos);

    const int maxIter = 20;
    int toPlace = (int)mStage;
    std::uniform_real_distribution<float> xrange(edgeOffset/2.0f, Game::ScreenWidth - edgeOffset/2.0f);
    std::uniform_real_distribution<float> yrange(edgeOffset/2.0f, Game::ScreenHeight - edgeOffset/2.0f);
    std::uniform_real_distribution<float> rotrange(0.0f, 360.0f);
    std::random_device rd;

    #ifdef DEBUG
    /* Fix the seed. */
    (void)rd;
    std::mt19937 rng(5); /* This puts the first ship in a good spot for testing. */
    #else
    std::mt19937 rng(rd());
    #endif

    /* Place the enemies. */
    while (toPlace > 0)
    {
        int iter = 0;
        while (iter < maxIter)
        {
            const sf::Vector2f enemyPos(xrange(rng), yrange(rng));
            const float enemyAngle = rotrange(rng);
            if (validEnemyPos(enemyPos, placed, playerOffset))
            {
                EnemyCreator(mTextureManager, enemyPos, enemyAngle).create(
                    mEntityManager.create());
                placed.push_back(enemyPos);
                break;
            }

            iter++;
        }

        if (iter == maxIter)
        {
            #ifdef DEBUG
            std::cout << "Could not place enemy\n";
            #endif
        }

        toPlace--;
    }
}

bool StageSystem::validEnemyPos(
    const sf::Vector2f &pos,
    const std::vector<sf::Vector2f> &placed,
    const float threshold) const
{
    /* Don't spawn in the black hole */
    const sf::Vector2f bhPos = sf::Vector2f(
        Game::BHCenterX,
        Game::BHCenterY);

    const float bhThreshold = Game::BHRadius*Game::BHRadius + threshold/2.0f;
    if (distsq(pos, bhPos) < bhThreshold)
    {
        return false;
    }

    /* Don't spawn on top of the player or on top of other ships. */
    for (const sf::Vector2f &p : placed)
    {
        if (distsq(pos, p) < threshold)
        {
            return false;
        }
    }

    return true;
}

void StageSystem::receive(const WinGameEvent &event)
{
    (void)event;
    mStage = 0;
}

void StageSystem::receive(const LoseGameEvent &event)
{
    (void)event;
    mStage = 0;
}
