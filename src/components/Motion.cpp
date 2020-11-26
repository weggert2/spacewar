#include "Motion.hpp"

Motion::Motion(
    const double linearSpeed,
    const double angularSpeed):
        mCurrSpeed(0.0),
        mCurrOmega(0.0),
        mSpeed(linearSpeed),
        mOmega(angularSpeed)
{
}

double Motion::getSpeed() const
{
    return mCurrSpeed;
}

double Motion::getOmega() const
{
    return mCurrOmega;
}

void Motion::setImpulseUp(
    const bool choice)
{
    mCurrSpeed = choice ? -mSpeed : 0.0;
}

void Motion::setImpulseDown(
    const bool choice)
{
    mCurrSpeed = choice ? mSpeed : 0.0;
}

void Motion::setRotateLeft(
    const bool choice)
{
    mCurrOmega = choice ? -mOmega : 0.0;
}

void Motion::setRotateRight(
    const bool choice)
{
    mCurrOmega = choice ? mOmega : 0.0;
}
