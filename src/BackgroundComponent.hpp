#pragma once

#include <entityx/Entity.h>

class BackgroundComponent : public entityx::Component<BackgroundComponent>
{
public:
    BackgroundComponent() = default;
};
