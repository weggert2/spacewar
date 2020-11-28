#include "Projectile.hpp"

Projectile::Projectile(
    const double currDuration,
    const double durationCoeff,
    const double baseDuration,
    const double damageCoeff,
    const double baseDamage):
        mCurrDuration(currDuration),
        mDurationCoeff(durationCoeff),
        mBaseDuration(baseDuration),
        mDamageCoeff(damageCoeff),
        mBaseDamage(baseDamage)
{
}

void Projectile::increaseDuration(const double dt)
{
    mCurrDuration += dt;
}

double Projectile::getDuration() const
{
    return mCurrDuration;
}

double Projectile::getDamage() const
{
    return mBaseDamage*mDamageCoeff;
}

double Projectile::getMaxDuration() const
{
    return mBaseDuration*mDurationCoeff;
}

