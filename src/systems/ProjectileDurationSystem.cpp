/**
 * @file
 *
 * $Id: ProjectileDurationSystem.cpp $
 * @author Bill Eggert
 */

#include "ProjectileDurationSystem.hpp"

#include "components/Projectile.hpp"

void ProjectileDurationSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    Projectile::Handle projectile;

    for (entityx::Entity e : entities.entities_with_components(projectile))
    {
        projectile->increaseDuration(dt);
        if (projectile->getDuration() > projectile->getMaxDuration())
        {
            e.destroy();
        }
    }
}
