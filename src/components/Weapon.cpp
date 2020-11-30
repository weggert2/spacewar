/**
 * @file
 *
 * $Id: Weapon.cpp $
 * @author Bill Eggert
 */

#include "Weapon.hpp"

Weapon::Weapon(
    const float currCoolDown,
    const bool active,
    const float maxCooldown,
    const float damageCoeff):
        mCurrCooldown(currCoolDown),
        mActive(active),
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
    /* Prevent underflow, although it would take a _very_ long time. */
    if (mCurrCooldown >= 0.0f)
    {
        mCurrCooldown -= dt;
    }
}

float Weapon::getCooldown() const
{
    return mCurrCooldown;
}

void Weapon::resetCooldown()
{
    mCurrCooldown = mMaxCooldown;
}
