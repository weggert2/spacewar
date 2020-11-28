#include "CollisionSystem.hpp"

#include "components/Enemy.hpp"
#include "components/Hitbox.hpp"
#include "components/Player.hpp"
#include "components/Position.hpp"
#include "components/Projectile.hpp"

template <typename T, typename U>
static void entityCollision(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    /* Dumb n^2 collision detection. We could do scan and sweep, or maintain
     * an AABB tree to do this faster. We have so few objects that this is
     * easier/faster to implement. */

    typename T::Handle handle1;
    Position::Handle pos1;
    Hitbox::Handle box1;
    for (entityx::Entity e1 : entities.entities_with_components(handle1, pos1, box1))
    {
        typename U::Handle handle2;
        Position::Handle pos2;
        Hitbox::Handle box2;
        for (entityx::Entity e2 : entities.entities_with_components(handle1, pos2, box2))
        {
            if (box1->collides(*pos1, *pos2, *box2))
            {
                std::cout << "Collision!\n";
            }
        }
    }
}

void CollisionSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    entityCollision<Player, Projectile>(entities, events, dt);
    // /* Intersection of enemy and projectile. */
    // Enemy::Handle enemy;
    // Position::Handle enemyPos;
    // Hitbox::handle enemyBox;
    // for (Entity ePlayer : entities_with_components(enemy, enemyPos, enemyBox))
    // {
    //     Projectile::Handle proj;
    //     Position::Handle projPos;
    //     Hitbox::handle
    //     for (Entity eProj : entities_with_components(proj, projPos))
    //     {
    //         // ??
    //     }
    // }

    /* Intersection of player and projectile. */

}
