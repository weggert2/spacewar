#pragma once

#include "MenuBase.hpp"

class SplashScreen : public MenuBase
{
public:
    void update(
        entityx::EventManager &events,
        float dt);

    void draw(
        sf::RenderWindow &window);
}
