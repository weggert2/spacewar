#pragma once

#include <entityx/Entity.h>
#include <SFML/Window/Keyboard.hpp>

/**
 * The component representing controls (movement, fire keys)
 */

class Control : public entityx::Component<Control>
{
public:
    Control(
        const sf::Keyboard::Key up,
        const sf::Keyboard::Key left,
        const sf::Keyboard::Key down,
        const sf::Keyboard::Key right,
        const sf::Keyboard::Key shoot);

    /* Bind new keys. */
    void bindUp(const sf::Keyboard::Key k);
    void bindLeft(const sf::Keyboard::Key k);
    void bindDown(const sf::Keyboard::Key k);
    void bindRight(const sf::Keyboard::Key k);
    void bindShoot(const sf::Keyboard::Key k);

    sf::Keyboard::Key getBindUp() const;
    sf::Keyboard::Key getBindLeft() const;
    sf::Keyboard::Key getBindDown() const;
    sf::Keyboard::Key getBindRight() const;
    sf::Keyboard::Key getBindShoot() const;

private:
    sf::Keyboard::Key mUp;
    sf::Keyboard::Key mLeft;
    sf::Keyboard::Key mDown;
    sf::Keyboard::Key mRight;
    sf::Keyboard::Key mShoot;
}
