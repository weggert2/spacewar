#include "PlayerControl.hpp"

PlayerControl::PlayerControl():
    mUp(sf::Keyboard::Up),
    mLeft(sf::Keyboard::Left),
    mDown(sf::Keyboard::Down),
    mRight(sf::Keyboard::Right),
    mShoot(sf::Keyboard::Space)
{
}

/* Bind new keys. */
void PlayerControl::bindUp(const sf::Keyboard::Key k)    { mUp    = k; }
void PlayerControl::bindLeft(const sf::Keyboard::Key k)  { mLeft  = k; }
void PlayerControl::bindDown(const sf::Keyboard::Key k)  { mDown  = k; }
void PlayerControl::bindRight(const sf::Keyboard::Key k) { mRight = k; }
void PlayerControl::bindShoot(const sf::Keyboard::Key k) { mShoot = k; }

sf::Keyboard::Key PlayerControl::getBindUp()    const { return mUp;    }
sf::Keyboard::Key PlayerControl::getBindLeft()  const { return mLeft;  }
sf::Keyboard::Key PlayerControl::getBindDown()  const { return mDown;  }
sf::Keyboard::Key PlayerControl::getBindRight() const { return mRight; }
sf::Keyboard::Key PlayerControl::getBindShoot() const { return mShoot; }
