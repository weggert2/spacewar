/**
 * @file
 *
 * $Id: Weapon.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <entityx/Entity.h>

class Weapon : public entityx::Component<Weapon>
{
public:
    Weapon(
        const float maxCooldown = 0.5,
        const float damageCoeff = 1.0);

    void setActive(const bool active);
    bool getActive() const;

    void decreaseCooldown(const float dt);
    float getCooldown() const;
    void resetCooldown();

private:
    /* The current time left before you can shoot again. */
    float mCurrCooldown;

    /* Whether the shoot button is being pressed. */
    bool mActive;

    /* The maximum amount of time to wait before you can shoot again. */
    const float mMaxCooldown;

    /* The damage multiplier of this weapon. */
    const float mDamageCoeff;
};
