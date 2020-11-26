#include <entityx/Entity.h>

class Motion : public entityx::Component<Motion>
{
public:
    Motion(
        const double linearSpeed = 200.0,
        const double angularSpeed = 100.0);

private:
    /**
     * The current values of the linear/angular speed. For now, either 0 or at
     * their settings mSpeed and mOmega.
     */
    double mCurrSpeed;
    double mCurrOmega;

    /**
     * The linear/angular speeds when the motion is active.
     */
    const double mSpeed;
    const double mOmega;
};