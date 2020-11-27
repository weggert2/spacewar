#pragma once

#include <entityx/Entity.h>
#include <SFML/Graphics.hpp>

class Background : public entityx::Component<Background>
{
public:
    explicit Background(
        const sf::Texture &texture);

public:
    sf::Sprite mSprite;
};
