/**
 * @file
 *
 * $Id: Projectile.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <entityx/Entity.h>

class Projectile : public entityx::Component<Projectile>
{
public:
    Projectile(
        const double currDuration = 0.0,
        const double durationCoeff = 1.0,
        const double baseDuration = 4.0,
        const double damageCoeff = 1.0,
        const double baseDamage = 1.0);

    void increaseDuration(const double dt);
    double getDuration() const;
    double getMaxDuration() const;
    double getDamage() const;

private:
    /* The current duration. */
    double mCurrDuration;

    const double mDurationCoeff;
    const double mBaseDuration;
    const double mDamageCoeff;
    const double mBaseDamage;
};
