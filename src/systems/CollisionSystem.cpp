#include "CollisionSystem.hpp"

#include "components/Display.hpp"
#include "components/Enemy.hpp"
#include "components/Hitbox.hpp"
#include "components/Player.hpp"
#include "components/Position.hpp"
#include "components/Projectile.hpp"

/* A little hack to do easy hitboxes.
 * TODO: Upgrade to use the real hitbox component. */
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

/**
 * Detect collision between two entities - applying damage to them if
 * it exists.
 */
template <typename T, typename U>
static void detectCollisions(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt,
    const float hitbox1Fac = 0.45,
    const float hitbox2Fac = 1.0)
{
    (void)events;

    /* Dumb n^2 collision detection. We could do scan and sweep, or maintain
     * an AABB tree to do this faster. We have so few objects that this is
     * easier/faster to implement. */

    typename T::Handle handle1;
    Position::Handle pos1;
    Display::Handle display1;
    for (entityx::Entity e1 : entities.entities_with_components(handle1, pos1, display1))
    {
        typename U::Handle handle2;
        Position::Handle pos2;
        Display::Handle display2;
        bool e1Destroyed = false;
        for (entityx::Entity e2 : entities.entities_with_components(handle2, pos2, display2))
        {
            if (e1.id() == e2.id())
                continue;

            const sf::FloatRect rect1 = adjustHitbox(
                display1->mSprite.getGlobalBounds(),
                hitbox1Fac);

            const sf::FloatRect rect2 = adjustHitbox(
                display2->mSprite.getGlobalBounds(),
                hitbox2Fac);

            static bool line = false;
            if (rect1.intersects(rect2))
            {
                /* TODO: Animation. */
                e2.destroy();
                e1Destroyed = true;
            }
        }

        if (e1Destroyed)
            e1.destroy();
    }
}

void CollisionSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    detectCollisions<Player, Projectile>(entities, events, dt);
    detectCollisions<Enemy, Projectile>(entities, events, dt);
    detectCollisions<Projectile, Projectile>(entities, events, dt);
}
