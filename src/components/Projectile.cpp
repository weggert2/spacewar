#include "Projectile.hpp"

Projectile::Projectile(
    const entityx::Entity::Id ownerId,
    const double maxDuration,
    const double currDuration,
    const double damage):
        mOwnerId(ownerId),
        mMaxDuration(maxDuration),
        mCurrDuration(currDuration),
        mDamage(damage)
{
}
