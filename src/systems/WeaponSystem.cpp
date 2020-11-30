/**
 * @file
 *
 * $Id: WeaponSystem.cpp $
 * @author Bill Eggert
 */

#include "WeaponSystem.hpp"

#include "EntityFactory.hpp"
#include "Events.hpp"

#include "components/Player.hpp"
#include "components/Position.hpp"
#include "components/Enemy.hpp"
#include "components/Weapon.hpp"

#include "math_utils.hpp"

WeaponSystem::WeaponSystem(
    const TextureManager &textureManager):
        mTextureManager(textureManager)
{
}

void WeaponSystem::update(
    entityx::EntityManager &entities,
    entityx::EventManager &eventManager,
    const double dt)
{
    Position::Handle position;
    Weapon::Handle weapon;

    for (entityx::Entity e : entities.entities_with_components(position, weapon))
    {
        if (e.has_component<Enemy>())
        {
            std::cout
                << e.id() << ": "
                << weapon->getCooldown() << ", "
                << weapon->getActive() << '\n';
        }
        weapon->decreaseCooldown((float)dt);
        if (weapon->getCooldown() > 0.0f || !weapon->getActive())
        {
            continue;
        }

        if (weapon->getCooldown() <= 0.0f)
        {
            weapon->resetCooldown();
        }

        TextureId textureId;
        SoundId soundId;

        if (e.has_component<Player>())
        {
            textureId = TextureId::PlayerBullet;
            soundId = SoundId::PlayerShoot;
        }
        else
        {
            textureId = TextureId::EnemyBullet;
            soundId = SoundId::EnemyShoot;
        }

        const ProjectileCreator::TextureInfo textureInfo {
            textureId, 1.0f, 1.0f, 1.0f, 1.0f };

        const float theta = position->getTheta();

        /* Move the bulletPos in the direction of the heading so the bullet
         * isn't immediately in collision */
        const sf::Vector2f bulletPos =
            position->getPos() + rotate(position->getOffset(), theta);

        ProjectileCreator creator(
            mTextureManager,
            textureInfo,
            bulletPos,
            theta);

        creator.create(entities.create());
        eventManager.emit<PlaySoundEvent>(soundId);
    }
}
