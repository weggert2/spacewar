/**
 * @file
 *
 * $Id: Hitbox.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <entityx/Entity.h>

class Position;

/**
 * A hitbox component. Ships, bullets, black holes have these.
 */

class Hitbox : public entityx::Component<Hitbox>
{
public:
    Hitbox(
        const float width,
        const float height);

    bool collides(
        const Position &thisPos,
        const Position &otherPos,
        const Hitbox &otherBox) const;

    float getWidth() const;
    float getHeight() const;

private:
    const float mWidth;
    const float mHeight;
};
