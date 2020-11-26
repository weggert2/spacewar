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
        const size_t pointValue = 10);

    size_t getPointValue() const;

private:
    const EnemyType mType;
    const size_t mPointValue;
}
