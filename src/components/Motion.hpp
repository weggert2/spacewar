#include <entityx/Entity.h>

class Motion : public entityx::Component<Motion>
{
public:
    Motion(
        const float currSpeed = 0.0f,
        const float currOmega = 0.0f,
        const float linearSpeed = 300.0f,
        const float angularSpeed = 200.0f);

    float getSpeed() const;
    float getOmega() const;

    void setImpulse(const bool up, const bool down);
    void setRotate(const bool left, const bool right);

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
