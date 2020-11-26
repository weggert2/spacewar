#pragma once

#include <entityx/Entity.h>

/**
 * A hitbox component. Ships, bullets, black holes have these.
 */

class Hitbox : public entityx::Component<Hitbox>
{
public:
    Hitbox(
        const double width,
        const double height);

    bool collides(
        const Position &thisPos,
        const Position &otherPos,
        const Hitbox &otherBox) const;

    double getWidth() const;
    double getHeight() const;

private:
    const double mWidth;
    const double mHeight;
}
