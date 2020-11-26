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
