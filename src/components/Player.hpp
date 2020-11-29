/**
 * @file
 *
 * $Id: Player.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <entityx/Entity.h>

class Player : public entityx::Component<Player>
{
public:
    Player() = default;
};
