#pragma once

#include <entityx/Entity.h>

enum class EnemyType
{
    ship,
    asteroid,
    boss,
};

class Enemy : public entityx::Component<Enemy>
{
public:
    explicit Enemy(
        const EnemyType type = EnemyType::ship,
        const float pointValue = 10.0f);

    float getPointValue() const;

private:
    const EnemyType mType;
    const float mPointValue;
};
