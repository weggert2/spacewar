/**
 * @file
 *
 * $Id: Health.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <entityx/Entity.h>

class Health : public entityx::Component<Health>
{
public:
    explicit Health(
        const double maxHealth);

    void changeHealth(
        const double dHealth);

    double getCurrHealth() const;
    double getMaxHealth() const;

private:
    double mCurrHealth;
    const double mMaxHealth;
};
