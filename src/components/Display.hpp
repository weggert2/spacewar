/**
 * @file
 *
 * $Id: Display.hpp $
 * @author Bill Eggert
 */

#pragma once

#include <entityx/Entity.h>
#include <SFML/Graphics.hpp>

class Display : public entityx::Component<Display>
{
public:
    Display(
        const sf::Texture &texture,
        const float scaleX = 0.4f,
        const float scaleY = 0.4f,
        const float origX = 1.0f,
        const float origY = 1.35f);

    sf::FloatRect getGlobalBounds() const;

public:
    sf::Sprite mSprite;
};
