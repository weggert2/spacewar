/**
 * @file
 *
 * $Id: Radius.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <entityx/Entity.h>

class Radius : public entityx::Component<Radius>
{
public:
    explicit Radius(
        const float radius):
            mRadius(radius)
    {
    }

    float get() const
    {
        return mRadius;
    }

private:
    const float mRadius;
};
