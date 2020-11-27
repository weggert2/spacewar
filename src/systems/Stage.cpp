#include "Stage.hpp"

#include "components/Display.hpp"
#include "components/Position.hpp"
#include "components/Player.hpp"

#include "Game.hpp"
#include "Events.hpp"
#include "EntityFactory.hpp"

#include <random>
#include <set>

#define DEBUG 1

Stage::Stage(
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

void Stage::subscribeEvents()
{
    mEventManager.subscribe<StartGameEvent>(*this);
    mEventManager.subscribe<StageClearedEvent>(*this);
}

void Stage::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    /* Nothing needed, I think? */
    (void)entities;
    (void)events;
    (void)dt;
}

void Stage::receive(
    const StartGameEvent &event)
{
    /* Make the background. */
    BackgroundCreator(mTextureManager).create(mEntityManager.create());
    PlayerCreator(mTextureManager).create(mEntityManager.create());

    /* Clear the zero'th stage. */
    mEventManager.emit<StageClearedEvent>();
}

/* Hack together a comparator so we can put sf::Vector2f's in a set.
 * We'll close our eyes to float comparisons for now, since we don't care
 * about floats that are close to each other. */
struct PosCmp
{
    bool operator()(
        const sf::Vector2f &a,
        const sf::Vector2f &b) const
    {
        if (a.x == b.x)
            return a.y < b.y;
        return a.x < b.x;
    }
};

/**
 * Returns the distance (squared) between two points.
 */
static float distsq(
    const sf::Vector2f &a,
    const sf::Vector2f &b)
{
    const float dx = a.x-b.x;
    const float dy = a.y-b.y;

    return dx*dx + dy*dy;
}

void Stage::receive(
    const StageClearedEvent &event)
{
    mStage++;

    /*
     * We want to place mStage enemies such that they:
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
    const float playerOffset = 5*edgeOffset;

    std::set<sf::Vector2f, PosCmp> placed;
    placed.insert(playerPos);

    const int maxIter = 20;
    int toPlace = mStage;
    std::uniform_real_distribution<float> xrange(edgeOffset, Game::screenWidth-edgeOffset);
    std::uniform_real_distribution<float> yrange(edgeOffset, Game::screenHeight-edgeOffset);
    std::random_device rd;

    while (toPlace > 0)
    {
        int iter = 0;
        while (iter < maxIter)
        {
            #ifdef DEBUG
            /* Fix the seed. */
            (void)rd;
            std::mt19937 rng(iter);
            #else
            std::mt19937 rng(rd());
            #endif

            const sf::Vector2f enemyPos(xrange(rng), yrange(rng));
            if (distsq(playerPos, enemyPos) > playerOffset)
            {
                EnemyCreator(mTextureManager).create(mEntityManager.create());
                break;
            }
        }

        toPlace--;
    }
}

void Stage::getPlayerData(
    sf::Vector2f &playerPos,
    float &offset) const
{
    Player::Handle player;
    Position::Handle position;
    Display::Handle display;

    /* I don't know if there's a better way to retrieve a specific entity. */
    for (entityx::Entity e : mEntityManager.entities_with_components(player, display, position))
    {
        /* There should only ever be one of these, so we don't mind iterating. */
        playerPos = position->getX();

        /* To prevent ships from being placed too close to the edge: */
        offset = display->mSprite.getLocalBounds().width/2.0;

        return;
    }

    std::cerr << "entity manager couldn't find a player\n";
}

