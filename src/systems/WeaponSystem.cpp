#include "WeaponSystem.hpp"

#include "components/Position.hpp"
#include "components/Weapon.hpp"

void WeaponSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &eventManager,
    const double dt)
{
    Position::Handle position;
    Weapon::Handle weapon;

    for (entityx::Entity e : entities.entities_with_components(position, weapon))
    {
        weapon->decreaseCooldown(dt);
        if (weapon->getCooldown() > 0 || !weapon->getActive())
        {
            continue;
        }
    }
}
