#pragma once

#include "MenuBase.hpp"

#include "AssetManager.hpp"

class GameManager;

class StartMenu : public MenuBase
{
public:
    StartMenu(
        const std::wstring &logoText,
        const sf::Font &logoFont,
        const sf::Font &menuFont,
        const GameManager &gameManager,
        const int logoFontSize);

    virtual void update(entityx::EventManager &events, float dt) override final;
    virtual void draw(sf::RenderWindow &window, const sf::Vector2f &pos) override final;
    virtual void select(entityx::EventManager &eventManager) override final;
    virtual void cancel(entityx::EventManager &eventManager) override final;
    virtual void up(entityx::EventManager &eventManager) override final;
    virtual void down(entityx::EventManager &eventManager) override final;
    virtual void left(entityx::EventManager &eventManager) override final;
    virtual void right(entityx::EventManager &eventManager) override final;

private:
    void resumeGame(entityx::EventManager &eventManager);

private:
    enum class MenuChoice
    {
        Play,
        Controls,
        Story,
        Credits,
        Quit,
    };

    sf::Text mLogoText;
    sf::Text mPlayText;
    sf::Text mStoryText;
    sf::Text mCreditsText;
    sf::Text mQuitText;
    sf::Text mControlsText;
    MenuChoice mMenuChoice;

    const std::vector<MenuChoice> choices {
        MenuChoice::Play,
        MenuChoice::Controls,
        MenuChoice::Story,
        MenuChoice::Credits,
        MenuChoice::Quit,
    };

    const GameManager &mGameManager;
};
