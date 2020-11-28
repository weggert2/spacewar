#include "StageSystem.hpp"

#include "components/Display.hpp"
#include "components/Position.hpp"
#include "components/Player.hpp"

#include "Game.hpp"
#include "Events.hpp"
#include "EntityFactory.hpp"
#include "math_utils.hpp"

#include <random>
#include <set>

#define DEBUG 1

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
}

void StageSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    /* Nothing needed, I think? */
    (void)entities;
    (void)events;
    (void)dt;
}

void StageSystem::receive(
    const StartGameEvent &event)
{
    (void)event;

    /* Make the background. */
    BackgroundCreator(mTextureManager).create(mEntityManager.create());
    PlayerCreator(mTextureManager).create(mEntityManager.create());

    /* Clear the zero'th stage. */
    mEventManager.emit<StageClearedEvent>();
}

void StageSystem::receive(
    const StageClearedEvent &event)
{
    (void)event;

    mStage++;

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

    sf::Vector2f playerPos;
    float edgeOffset;
    getPlayerData(playerPos, edgeOffset);
    const float playerOffset = edgeOffset*edgeOffset;

    std::vector<sf::Vector2f> placed;
    placed.push_back(playerPos);

    const int maxIter = 20;
    int toPlace = mStage;
    std::uniform_real_distribution<float> xrange(edgeOffset, Game::screenWidth-edgeOffset);
    std::uniform_real_distribution<float> yrange(edgeOffset, Game::screenHeight-edgeOffset);
    std::uniform_real_distribution<float> rotrange(0.0, 360.0);
    std::random_device rd;

    #ifdef DEBUG
    /* Fix the seed. */
    (void)rd;
    std::mt19937 rng(5);
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

        toPlace--;
    }
}

void StageSystem::getPlayerData(
    sf::Vector2f &playerPos,
    float &offset) const
{
    Player::Handle player;
    Position::Handle position;
    Display::Handle display;

    /* I don't know if there's a better way to retrieve a specific entity.
     * Some textbooks suggest that the Player should not be an entity at all,
     * probably for this reason. */
    for (entityx::Entity e : mEntityManager.entities_with_components(player, display, position))
    {
        (void)e;

        /* There should only ever be one of these, so we don't mind iterating. */
        playerPos = position->getX();

        /* To prevent ships from being placed too close to the edge: */
        offset = display->mSprite.getLocalBounds().width/2.0f;
        return;
    }

    std::cerr << "entity manager couldn't find a player\n";
}

bool StageSystem::validEnemyPos(
    const sf::Vector2f &pos,
    const std::vector<sf::Vector2f> &placed,
    const float threshold) const
{
    for (const sf::Vector2f &p : placed)
    {
        if (distsq(pos, p) < threshold)
        {
            return false;
        }
    }

    return true;
}
