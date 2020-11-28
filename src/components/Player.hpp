#pragma once

#include <entityx/Entity.h>

class Player : public entityx::Component<Player>
{
public:
    Player() = default;
};
