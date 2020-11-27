#include "Hitbox.hpp"

#include <SFML/Graphics/Rect.hpp>
#include "Position.hpp"

Hitbox::Hitbox(
    const double width,
    const double height):
        mWidth(width),
        mHeight(height)
{
}

double Hitbox::getWidth() const
{
    return mWidth;
}

double Hitbox::getHeight() const
{
    return mHeight;
}

bool Hitbox::collides(
    const Position &thisPos,
    const Position &otherPos,
    const Hitbox &otherBox) const
{
    /* We won't worry about the rotated box - we'll use take the AABB */
    const auto buildRect = [&](sf::Vector2f p, double w, double h) {
        return sf::Rect<float>(
            p.x - w/2.0,
            p.y - h/2.0,
            mWidth,
            mHeight);
    };

    const sf::Rect<float> thisRect = buildRect(
        thisPos.getX(),
        mWidth,
        mHeight);

    const sf::Rect<float> otherRect = buildRect(
        otherPos.getX(),
        otherBox.getWidth(),
        otherBox.getHeight());

    return thisRect.intersects(otherRect);
}
