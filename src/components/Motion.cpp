#include "Motion.hpp"

Motion::Motion(
    const float linearSpeed,
    const float angularSpeed):
        mCurrSpeed(0.0),
        mCurrOmega(0.0),
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

void Motion::setImpulseUp(
    const bool choice)
{
    mCurrSpeed = choice ? -mSpeed : 0.0f;
}

void Motion::setImpulseDown(
    const bool choice)
{
    mCurrSpeed = choice ? mSpeed : 0.0f;
}

void Motion::setRotateLeft(
    const bool choice)
{
    mCurrOmega = choice ? -mOmega : 0.0f;
}

void Motion::setRotateRight(
    const bool choice)
{
    mCurrOmega = choice ? mOmega : 0.0f;
}
