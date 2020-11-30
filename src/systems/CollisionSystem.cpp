/**
 * @file
 *
 * $Id: CollisionSystem.cpp $
 * @author Bill Eggert
 */

#include "CollisionSystem.hpp"

#include "components/Display.hpp"
#include "components/Enemy.hpp"
#include "components/Hitbox.hpp"
#include "components/Player.hpp"
#include "components/Position.hpp"
#include "components/Projectile.hpp"
#include "components/Radius.hpp"

#include "math_utils.hpp"

CollisionSystem::CollisionSystem(
    entityx::EventManager &eventManager):
        mEventManager(eventManager)
{
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
    const float d = (1.0f-2.0f*fac); /* How much to scale the height/width */
    const float l2 = r.left + fac*r.width; /* new left   */
    const float t2 = r.top + fac*r.height; /* new top    */
    const float w2 = d*r.width;    /* new width  */
    const float h2 = d*r.height;   /* new height */

    return sf::FloatRect(l2,t2,w2,h2);
}

/**
 * Detect collision between two entities - applying damage to them if
 * it exists.
 *
 * @tparam EntityType1 The first type of entity to retrieve
 * @tparam EntityType2 The second type of entity to retrieve
 * @tparam BoxType1 The type that defines how EntityType1 computes its global bounds.
 * @tparam BoxType2 The type that defines how EntityType2 computes its global bounds
 */
template<typename EntityType1, typename EntityType2>
void CollisionSystem::detectCollisions(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt,
    const float hitbox1Fac,
    const float hitbox2Fac)
{
    (void)events;
    (void)dt;

    /* Dumb n^2 collision detection. We could do scan and sweep, or maintain
     * an AABB tree to do this faster. We have so few objects that this is
     * easier/faster to implement. */

    typename EntityType1::Handle entity1;
    Display::Handle box1;
    for (entityx::Entity e1 : entities.entities_with_components(entity1, box1))
    {
        typename EntityType2::Handle entity2;
        Display::Handle box2;
        bool e1Destroyed = false;
        for (entityx::Entity e2 : entities.entities_with_components(entity2, box2))
        {
            if (e1.id() == e2.id())
                continue;

            const sf::FloatRect bounds1 = box1->getGlobalBounds();
            const sf::FloatRect bounds2 = box2->getGlobalBounds();

            const sf::FloatRect rect1 = adjustHitbox(bounds1, hitbox1Fac);
            const sf::FloatRect rect2 = adjustHitbox(bounds2, hitbox2Fac);

            if (intersects(rect1, rect2))
            {
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
        }
    }
}

template<typename EntityType>
void CollisionSystem::detectBHCollisions(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt,
    const float hitboxFac)
{
    (void)events;
    (void)dt;

    Position::Handle bhPos;
    Radius::Handle bhRad;
    for (entityx::Entity bh : entities.entities_with_components(bhPos, bhRad))
    {
        (void)bh;

        const sf::Vector2f &pos = bhPos->getPos();
        const float rad = bhRad->get();

        typename EntityType::Handle entity;
        Display::Handle box;
        for (entityx::Entity e : entities.entities_with_components(entity, box))
        {
            const sf::FloatRect bounds = box->getGlobalBounds();
            const sf::FloatRect rect = adjustHitbox(bounds, hitboxFac);

            if (intersects(rect, Circle(pos, rad)))
            {
                destroyEntity(e);
            }
        }
    }
}

void CollisionSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    detectCollisions<Player, Enemy>(entities, events, dt, 0.25f, 0.25f);
    detectCollisions<Player, Projectile>(entities, events, dt);
    detectCollisions<Enemy, Projectile>(entities, events, dt);
    detectCollisions<Projectile, Projectile>(entities, events, dt, 0.35f, 0.35f);

    detectBHCollisions<Projectile>(entities, events, dt, 0.35f);
    detectBHCollisions<Player>(entities, events, dt);
    detectBHCollisions<Enemy>(entities, events, dt);
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
