#include "EnemyControlSystem.hpp"

#include "components/EnemyControl.hpp"
#include "components/Motion.hpp"
#include "components/Weapon.hpp"
#include "components/Position.hpp"

void EnemyControlSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    (void)events;
    (void)dt;

    /* Let's try out a different syntax. */
    size_t i = 0;
    entities.each<EnemyControl, Motion, Weapon, Position>([&](
        entityx::Entity e,
        EnemyControl &control,
        Motion &motion,
        Weapon &weapon,
        Position &position)
    {
        (void)e;
        (void)control;
        (void)motion;
        (void)position;
        (void)weapon;
        weapon.setActive(true);
        i++;
    });

    std::cout << "num enemies: " << i << std::endl;
}
