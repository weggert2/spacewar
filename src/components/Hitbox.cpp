#include "Hitbox.hpp"

#include <SFML/Graphics/Rect.hpp>
#include "Position.hpp"

Hitbox::Hitbox(
    const float width,
    const float height):
        mWidth(width),
        mHeight(height)
{
}

float Hitbox::getWidth() const
{
    return mWidth;
}

float Hitbox::getHeight() const
{
    return mHeight;
}

bool Hitbox::collides(
    const Position &thisPos,
    const Position &otherPos,
    const Hitbox &otherBox) const
{
    /* We won't worry about the rotated box - we'll use take the AABB */
    const auto buildRect = [&](sf::Vector2f p, float w, float h) {
        return sf::FloatRect(
            p.x - w/2.0f,
            p.y - h/2.0f,
            mWidth,
            mHeight);
    };

    const sf::FloatRect thisRect = buildRect(
        thisPos.getPos(),
        mWidth,
        mHeight);

    const sf::FloatRect otherRect = buildRect(
        otherPos.getPos(),
        otherBox.getWidth(),
        otherBox.getHeight());

    return thisRect.intersects(otherRect);
}
