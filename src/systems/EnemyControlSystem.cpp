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
    });

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
     * The enemies aren't suicidal, so if we get too close to the player, stop.
     */
    const float cosTh = dot(heading, d);

    if (dist < Game::ScreenWidth/5.0f)
    {
        motion.setImpulse(false, false);
    }
    else
    {
        motion.setImpulse(cosTh > 0.0f, false);
    }

    /* Get the quadrant angle between us and the player. This will tell us
     * which direction to turn. When we're pointed right at the player,
     * and within a certain distance, shoot.
     *
     * However, if our path takes us through the black hole, that's no good
     * either! We could make the ships avoid the black hole with some ray-circle
     * intersection, and then some not-so-tricky pathfinding around it. But,
     * after playtesting, the AI is hard enough to beat already. Moreover,
     * it is FUN to trick them into killing themselves in the black hole. So
     * let's deliberately not do the hard math, since I think it's more fun!
     */
    const float th = std::atan2(cross(heading, d), cosTh);
    const float threshold = 0.0f;
    motion.setRotate(th < -threshold, th > threshold);
    weapon.setActive(std::fabs(th) < M_PI/8.0f);
}
