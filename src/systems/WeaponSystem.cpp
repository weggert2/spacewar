#include "WeaponSystem.hpp"

#include "EntityFactory.hpp"

#include "components/Player.hpp"
#include "components/Position.hpp"
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
        weapon->decreaseCooldown(dt);
        if (weapon->getCooldown() > 0.0 || !weapon->getActive())
        {
            continue;
        }

        if (weapon->getCooldown() <= 0.0)
        {
            weapon->resetCooldown();
        }

        const TextureId textureId = e.has_component<Player>() ?
            TextureId::PlayerBullet : TextureId::EnemyBullet;

        const ProjectileCreator::TextureInfo textureInfo {
            .mTextureId = textureId,
            .mScaleX = 1.0f,
            .mScaleY = 1.0f,
            .mOrigX = 1.0f,
            .mOrigY = 1.0f,
        };

        const float theta = position->getTheta();

        /* Move the bulletPos in the direction of the heading so the bullet
         * isn't immediately in collision */
        const sf::Vector2f bulletPos =
            position->getX() + rotate(position->getOffset(), theta);

        ProjectileCreator creator(
            mTextureManager,
            textureInfo,
            bulletPos,
            theta);

        creator.create(entities.create());
    }
}