#include "Motion.hpp"

Motion::Motion(
    const float currSpeed,
    const float currOmega,
    const float linearSpeed,
    const float angularSpeed):
        mCurrSpeed(currSpeed),
        mCurrOmega(currOmega),
        mSpeed(linearSpeed),
        mOmega(angularSpeed)
{
}

float Motion::getSpeed() const
{
    return mCurrSpeed;
}

float Motion::getOmega() const
{
    return mCurrOmega;
}

void Motion::setImpulse(
    const bool up,
    const bool down)
{
    if      (up)   mCurrSpeed = -mSpeed;
    else if (down) mCurrSpeed =  mSpeed;
    else           mCurrSpeed =  0.0f;
}

void Motion::setRotate(
    const bool left,
    const bool right)
{
    if      (left)  mCurrOmega = -mOmega;
    else if (right) mCurrOmega =  mOmega;
    else            mCurrOmega =  0.0f;
}
