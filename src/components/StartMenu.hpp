#pragma once

#include "MenuBase.hpp"

#include "AssetManager.hpp"

class StartMenu : public MenuBase
{
public:
    StartMenu(
        const TextManager &textManager,
        const FontManager &fontManager);

    virtual void update(entityx::EventManager &events, float dt) override final;
    virtual void draw(sf::RenderWindow &window, const sf::Vector2f &pos) override final;
    virtual void select(entityx::EventManager &eventManager) override final;
    virtual void cancel(entityx::EventManager &eventManager) override final;
    virtual void up(entityx::EventManager &eventManager) override final;
    virtual void down(entityx::EventManager &eventManager) override final;
    virtual void left(entityx::EventManager &eventManager) override final;
    virtual void right(entityx::EventManager &eventManager) override final;

private:
    enum class MenuChoice
    {
        Play,
        Quit,
    };

    sf::Text mLogoText;
    sf::Text mPlayText;
    sf::Text mQuitText;
    MenuChoice mMenuChoice;
};
