#include "Background.hpp"

Background::Background(
    const sf::Texture &texture):
        mSprite()
{
    mSprite.setTexture(texture);
}
