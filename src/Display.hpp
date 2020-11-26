#pragma once

#include <entityx/Entity.h>
#include <SFML/Graphics.hpp>

class Display : public entityx::Component<Display>
{
public:
    explicit Display(
        const sf::Texture &texture);

public:
    sf::Sprite mSprite;
}
