#include "EnemyControlSystem.hpp"

#include "components/EnemyControl.hpp"
#include "components/Motion.hpp"
#include "components/Weapon.hpp"
#include "components/Position.hpp"

#include "Game.hpp"
#include "entity_utils.hpp"
#include "math_utils.hpp"

void EnemyControlSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    (void)events;
    (void)dt;

    const sf::Vector2f bhPos = Game::getBHPos();
    const sf::Vector2f playerPos = getPlayerPos(entities);

    size_t i = 0;
    entities.each<EnemyControl, Motion, Weapon, Position>([&](
        entityx::Entity e,
        EnemyControl &control,
        Motion &motion,
        Weapon &weapon,
        Position &position)
    {
        pursuePlayer(motion, weapon, position, playerPos);
        // shootAtPlayer();
        // weapon.setActive(true);
        // i++;
    });

    // std::cout << "num enemies: " << i << std::endl;
}

void EnemyControlSystem::pursuePlayer(
    Motion &motion,
    Weapon &weapon,
    const Position &position,
    const sf::Vector2f &playerPos) const
{
    const sf::Vector2f &pos = position.getPos();
    const sf::Vector2f heading = normalize(computeHeading(position.getTheta()));
    const sf::Vector2f d = normalize(pos - playerPos);
    const float dist = std::sqrt(distsq(pos, playerPos));

    /* Get the cos of the angle between the player and the enemy.
     *
     * A value > 0 means we are pointing "towards" the player. Turn the thrusters
     * on in this case. Conversely, a value < 0 means we are pointing away,
     * so turn the thrusters off.
     *
     * The enemies aren't suicidal, so if we get too close to the player,
     * reverse thrust.
     */
    const float cosTh = dot(heading, d);

    if (dist < Game::ScreenWidth/5.0f)
    {
        motion.setImpulse(false, true);
    }
    else
    {
        motion.setImpulse(cosTh > 0.0f, false);
    }

    /* Get the quadrant angle between us and the player. This will tell us
     * which direction to turn. When we're pointed right at the player,
     * and within a certain distance, shoot. */
    const float th = std::atan2(cross(heading, d), cosTh);
    const float threshold = 0.0f;
    motion.setRotate(th < -threshold, th > threshold);
    weapon.setActive(std::fabs(th) < M_PI/10.0f);
}
