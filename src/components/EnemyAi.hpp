/**
 * @file
 *
 * $Id: EnemyAi.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <entityx/Entity.h>

/**
 * The component representing the enemy gameplay logic.
 */
class EnemyAi : public entityx::Component<EnemyAi>
{
public:
    EnemyAi() = default;
};
