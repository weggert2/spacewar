#include "Control.hpp"

Control::Control(
    const sf::Keyboard::Key up,
    const sf::Keyboard::Key left,
    const sf::Keyboard::Key down,
    const sf::Keyboard::Key right,
    const sf::Keyboard::Key shoot):
        mUp(up),
        mLeft(left),
        mDown(down),
        mRight(right),
        mShoot(shoot)
{
}

/* Bind new keys. */
void Control::bindUp(const sf::Keyboard::Key k)    { up    = k; }
void Control::bindLeft(const sf::Keyboard::Key k)  { left  = k; }
void Control::bindDown(const sf::Keyboard::Key k)  { down  = k; }
void Control::bindRight(const sf::Keyboard::Key k) { right = k; }
void Control::bindShoot(const sf::Keyboard::Key k) { shoot = k; }

sf::Keyboard::Key getBindUp()    const { return up;    }
sf::Keyboard::Key getBindLeft()  const { return left;  }
sf::Keyboard::Key getBindDown()  const { return down;  }
sf::Keyboard::Key getBindRight() const { return right; }
sf::Keyboard::Key getBindShoot() const { return shoot; }
