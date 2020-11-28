#pragma once

#include <entityx/System.h>
#include <SFML/System/Vector2.hpp>

class MovementSystem : public entityx::System<MovementSystem>
{
public:
    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);

private:
    sf::Vector2f wrap(const sf::Vector2f &pos) const;
};
