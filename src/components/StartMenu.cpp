#include "StartMenu.hpp"
#include "Game.hpp"
#include "Events.hpp"

StartMenu::StartMenu(
    const std::wstring &logoText,
    const sf::Font &logoFont,
    const sf::Font &menuFont):
        mLogoText(),
        mPlayText(),
        mQuitText(),
        mMenuChoice(MenuChoice::Play)
{
    const auto setOrigin = [](sf::Text &t) {
        const sf::FloatRect sz = t.getLocalBounds();
        t.setOrigin(sz.width/2.0f, sz.height/2.0f);
    };

    mLogoText.setFont(logoFont);
    mLogoText.setCharacterSize(20);
    mLogoText.setString(logoText);
    mLogoText.setFillColor(sf::Color::Red);
    setOrigin(mLogoText);

    const auto initMenu = [&](sf::Text &t, const std::string &s) {
        t.setFont(menuFont);
        t.setCharacterSize(60);
        t.setString(s);
        setOrigin(t);
    };

    initMenu(mPlayText,     "Play");
    initMenu(mControlsText, "Controls");
    initMenu(mQuitText,     "Quit");
}

void StartMenu::update(
    entityx::EventManager &events,
    float dt)
{
    (void)events;
    (void)dt;

    /* Nothing needed. */
}

void StartMenu::draw(
    sf::RenderWindow &window,
    const sf::Vector2f &pos)
{
    mLogoText.setPosition(pos);

    const auto nextY = [](const sf::Text &t, const float spacing = 40.0f) {
        const sf::FloatRect sz = t.getGlobalBounds();
        return sz.top + sz.height + spacing;
    };

    mPlayText.setPosition(pos.x,     nextY(mLogoText));
    mControlsText.setPosition(pos.x, nextY(mPlayText, 20.0f));
    mQuitText.setPosition(pos.x,     nextY(mControlsText));

    mPlayText.setStyle(sf::Text::Regular);
    mControlsText.setStyle(sf::Text::Regular);
    mQuitText.setStyle(sf::Text::Regular);

    switch (mMenuChoice)
    {
        case MenuChoice::Play:     mPlayText.setStyle(sf::Text::Underlined);     break;
        case MenuChoice::Controls: mControlsText.setStyle(sf::Text::Underlined); break;
        case MenuChoice::Quit:     mQuitText.setStyle(sf::Text::Underlined);     break;
    }

    window.draw(mLogoText);
    window.draw(mPlayText);
    window.draw(mControlsText);
    window.draw(mQuitText);
}

void StartMenu::select(
    entityx::EventManager &eventManager)
{
    switch (mMenuChoice)
    {
        case MenuChoice::Play:     eventManager.emit<StartGameEvent>();    break;
        case MenuChoice::Quit:     eventManager.emit<QuitGameEvent>();     break;
        case MenuChoice::Controls: eventManager.emit<ShowControlsEvent>(); break;
    }
}

void StartMenu::cancel(
    entityx::EventManager &eventManager)
{
    (void)eventManager;

    /* Nothing needed. */
}

void StartMenu::up(
    entityx::EventManager &eventManager)
{
    (void)eventManager;

    switch (mMenuChoice)
    {
        case MenuChoice::Play:     mMenuChoice = MenuChoice::Quit;     break;
        case MenuChoice::Controls: mMenuChoice = MenuChoice::Play;     break;
        case MenuChoice::Quit:     mMenuChoice = MenuChoice::Controls; break;
    }
}

void StartMenu::down(
    entityx::EventManager &eventManager)
{
    (void)eventManager;
    switch (mMenuChoice)
    {
        case MenuChoice::Play:     mMenuChoice = MenuChoice::Controls; break;
        case MenuChoice::Controls: mMenuChoice = MenuChoice::Quit;     break;
        case MenuChoice::Quit:     mMenuChoice = MenuChoice::Play;     break;
    }
}

void StartMenu::left(
    entityx::EventManager &eventManager)
{
    /* No left/right in this menu. */
    (void)eventManager;
}

void StartMenu::right(
    entityx::EventManager &eventManager)
{
    /* No left/right in this menu. */
    (void)eventManager;
}
