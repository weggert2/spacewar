#pragma once

#include <entityx/Entity.h>

class Weapon : public entityx::Component<Weapon>
{
public:
    Weapon(
        const double maxCooldown,
        const double damageCoeff = 1.0);
public:
    double mCurrCooldown;
    bool mActive;

private:
    const double mMaxCooldown;
    const double mDamageCoeff;
};
