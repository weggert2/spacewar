#pragma once

#include <entityx/Entity.h>
#include <SFML/Graphics.hpp>

class Background : public entityx::Component<Background>
{
public:
    explicit Background(
        const sf::Texture &texture);

    const sf::Sprite &get() const;

private:
    sf::Sprite mSprite;
};
