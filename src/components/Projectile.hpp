#pragma once

#include <entityx/Entity.h>

class Projectile : public entityx::Component<Projectile>
{
public:
    Projectile(
        const entityx::Entity::Id ownerId,
        const double maxDuration,
        const double currDuration,
        const double damage);

private:
    entityx::Entity::Id mOwnerId;
    double mMaxDuration;
    double mCurrDuration;
    double mDamage;
};
