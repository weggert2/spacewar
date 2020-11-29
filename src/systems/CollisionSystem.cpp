#include "CollisionSystem.hpp"

#include "components/Display.hpp"
#include "components/Enemy.hpp"
#include "components/Hitbox.hpp"
#include "components/Player.hpp"
#include "components/Position.hpp"
#include "components/Projectile.hpp"

CollisionSystem::CollisionSystem(
    entityx::EventManager &eventManager):
        mEventManager(eventManager)
{
    mEventManager.subscribe<LoseGameEvent>(*this);
}

/*
 * A little hack to do easy hitboxes.
 * TODO: Upgrade to use the real hitbox component. I implemented one,
 * but it didn't seem to give me the right answer... so go revisit that
 * when we can.
 */
static sf::FloatRect adjustHitbox(
    const sf::FloatRect &r,
    const float fac)
{
    const float d = (1.0-2.0*fac); /* How much to scale the height/width */
    const float l2 = r.left + fac*r.width; /* new left   */
    const float t2 = r.top + fac*r.height; /* new top    */
    const float w2 = d*r.width;    /* new width  */
    const float h2 = d*r.height;   /* new height */

    return sf::FloatRect(l2,t2,w2,h2);
}

static void printRect(
    const sf::FloatRect &r)
{
    std::cout << r.left << ", " << r.top << ", "
              << r.width << ", " << r.height << std::endl;
}

/* See comment in detectCollisions for the explanation of this shameful hack. */
static bool firstCycle = true;

/**
 * Detect collision between two entities - applying damage to them if
 * it exists.
 */
template <typename T, typename U>
void CollisionSystem::detectCollisions(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt,
    const float hitbox1Fac,
    const float hitbox2Fac)
{
    (void)events;

    /* Dumb n^2 collision detection. We could do scan and sweep, or maintain
     * an AABB tree to do this faster. We have so few objects that this is
     * easier/faster to implement. */

    typename T::Handle handle1;
    Display::Handle display1;
    for (entityx::Entity e1 : entities.entities_with_components(handle1, display1))
    {
        typename U::Handle handle2;
        Display::Handle display2;
        bool e1Destroyed = false;
        for (entityx::Entity e2 : entities.entities_with_components(handle2, display2))
        {
            if (e1.id() == e2.id())
                continue;

            const sf::FloatRect bounds1 = display1->mSprite.getGlobalBounds();
            const sf::FloatRect bounds2 = display2->mSprite.getGlobalBounds();

            const sf::FloatRect rect1 = adjustHitbox(bounds1, hitbox1Fac);
            const sf::FloatRect rect2 = adjustHitbox(bounds2, hitbox2Fac);

            if (rect1.intersects(rect2))
            {

                /*
                 * I really don't know what's going on here. On the first cycle,
                 * the global bounding boxes of the enemy and the player are
                 * identical. After the first cycle, they're in the right spot.
                 * Maybe it's the ordering of how the systems are updated?
                 * I don't know. Let's hack around it for now.
                 *
                 * Obviously this is not appropriate for production code.
                 */
                if (firstCycle)
                {
                    firstCycle = false;
                    return;
                }
                /*
                 * TODO: Damage, don't destroy. Let another system do that.
                 * TODO: Animation.
                 */
                destroyEntity(e2);
                e1Destroyed = true;
            }
        }

        if (e1Destroyed)
        {
            destroyEntity(e1);
            // e1.destroy();
        }
    }
}

void CollisionSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    detectCollisions<Player, Enemy>(entities, events, dt, 0.25, 0.25);
    detectCollisions<Player, Projectile>(entities, events, dt);
    detectCollisions<Enemy, Projectile>(entities, events, dt);
    detectCollisions<Projectile, Projectile>(entities, events, dt, 0.35, 0.35);
}

void CollisionSystem::receive(
    const LoseGameEvent &event)
{
    firstCycle = true;
}

void CollisionSystem::destroyEntity(
    entityx::Entity e) const
{
    entityx::ComponentHandle<Enemy> enemy = e.component<Enemy>();
    entityx::ComponentHandle<Player> player = e.component<Player>();
    if (enemy)
    {
        mEventManager.emit<EnemyDestroyedEvent>(enemy->getPointValue());
        mEventManager.emit<PlaySoundEvent>(SoundId::EnemyHit);
    }
    else if (player)
    {
        mEventManager.emit<PlaySoundEvent>(SoundId::PlayerHit);
    }

    e.destroy();
}
