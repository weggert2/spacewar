#pragma once

#include <entityx/Entity.h>

class Weapon : public entityx::Component<Weapon>
{
public:
    Weapon(
        const double maxCooldown,
        const double damageCoeff = 1.0);

    void setActive(const bool active);
    bool getActive() const;

    void decreaseCooldown(const float dt);
    double getCooldown() const;
    void resetCooldown();

private:
    /* The current time left before you can shoot again. */
    double mCurrCooldown;

    /* Whether the shoot button is being pressed. */
    bool mActive;

    /* The maximum amount of time to wait before you can shoot again. */
    const double mMaxCooldown;

    /* The damage multiplier of this weapon. */
    const double mDamageCoeff;
};
