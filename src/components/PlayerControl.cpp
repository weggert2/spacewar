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
void Control::bindUp(const sf::Keyboard::Key k)    { mUp    = k; }
void Control::bindLeft(const sf::Keyboard::Key k)  { mLeft  = k; }
void Control::bindDown(const sf::Keyboard::Key k)  { mDown  = k; }
void Control::bindRight(const sf::Keyboard::Key k) { mRight = k; }
void Control::bindShoot(const sf::Keyboard::Key k) { mShoot = k; }

sf::Keyboard::Key Control::getBindUp()    const { return mUp;    }
sf::Keyboard::Key Control::getBindLeft()  const { return mLeft;  }
sf::Keyboard::Key Control::getBindDown()  const { return mDown;  }
sf::Keyboard::Key Control::getBindRight() const { return mRight; }
sf::Keyboard::Key Control::getBindShoot() const { return mShoot; }
