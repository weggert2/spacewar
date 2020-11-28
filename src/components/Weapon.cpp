#include "Weapon.hpp"

Weapon::Weapon(
    const double maxCooldown,
    const double damageCoeff):
        mCurrCooldown(0.0),
        mActive(false),
        mMaxCooldown(maxCooldown),
        mDamageCoeff(damageCoeff)
{
}

void Weapon::setActive(
    const bool active)
{
    mActive = active;
}

bool Weapon::getActive() const
{
    return mActive;
}

void Weapon::decreaseCooldown(
    const float dt)
{
    mCurrCooldown -= dt;
}

double Weapon::getCooldown() const
{
    return mCurrCooldown;
}

void Weapon::resetCooldown()
{
    mCurrCooldown = mMaxCooldown;
}
