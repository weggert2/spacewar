#include <entityx/Entity.h>

class Motion : public entityx::Component<Motion>
{
public:
    Motion(
        const float linearSpeed = 200.0,
        const float angularSpeed = 100.0);

    float getSpeed() const;
    float getOmega() const;

    void setImpulseUp(const bool choice);
    void setImpulseDown(const bool choice);
    void setRotateLeft(const bool choice);
    void setRotateRight(const bool choice);

private:
    /**
     * The current values of the linear/angular speed. For now, either 0 or at
     * their settings mSpeed and mOmega.
     */
    float mCurrSpeed;
    float mCurrOmega;

    /**
     * The linear/angular speeds when the motion is active.
     */
    const float mSpeed;
    const float mOmega;
};
