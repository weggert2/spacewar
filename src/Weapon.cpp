#include "Weapon.hpp"

Weapon::Weapon(
    const double maxCooldown,
    const double damageCoeff):
        mCurrCooldown(0.0),
        mActive(false),
        mMaxCooldown(maxCooldown)
{
}
