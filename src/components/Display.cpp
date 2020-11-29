/**
 * @file
 *
 * $Id: Display.cpp $
 * @author Bill Eggert
 */

#include "Display.hpp"

Display::Display(
    const sf::Texture &texture,
    const float scaleX,
    const float scaleY,
    const float origX,
    const float origY):
        mSprite()
{
    mSprite.setTexture(texture);
    mSprite.setScale(scaleX, scaleY);

    /* Approximates the center of mass as the "cockpit" */
    const auto size  = mSprite.getTexture()->getSize();
    const auto scale = mSprite.getScale();
    const sf::Vector2f spriteSize(
        size.x * scale.x,
        size.y * scale.y);

    /* 1.35 = magic number found by fiddling. */
    mSprite.setOrigin(origX*spriteSize.x, origY*spriteSize.y);
}

sf::FloatRect Display::getGlobalBounds() const
{
    return mSprite.getGlobalBounds();
}
