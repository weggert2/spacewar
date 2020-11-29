/**
 * @file
 *
 * $Id: Health.cpp $
 * @author Bill Eggert
 */

#include "Health.hpp"

Health::Health(
    const double maxHealth):
        mCurrHealth(maxHealth),
        mMaxHealth(maxHealth)
{
}

void Health::changeHealth(const double dHealth)
{
    mCurrHealth += dHealth;
}

double Health::getCurrHealth() const
{
    return mCurrHealth;
}

double Health::getMaxHealth() const
{
    return mMaxHealth;
}
