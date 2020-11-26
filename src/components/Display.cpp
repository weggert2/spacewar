#include "Display.hpp"

Display::Display(
    const sf::Texture &texture):
        mSprite()
{
    mSprite.setTexture(texture);
    mSprite.setScale(0.4f, 0.4f);

    /* Approximates the center of mass as the "cockpit" */
    const auto size  = mSprite.getTexture()->getSize();
    const auto scale = mSprite.getScale();
    const sf::Vector2f spriteSize(
        size.x * scale.x,
        size.y * scale.y);

    /* 1.35 = magic number found by fiddling. */
    mSprite.setOrigin(spriteSize.x, 1.35f*spriteSize.y);
}
