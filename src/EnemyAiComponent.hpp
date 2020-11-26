#pragma once

#include <entityx/Entity.h>

/**
 * The component representing the enemy gameplay logic.
 */
class EnemyAiComponent : public entityx::Component<Ai>
{
public:
    EnemyAi() = default;
};
