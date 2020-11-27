#include "StartMenu.hpp"
#include "Game.hpp"
#include "Events.hpp"

StartMenu::StartMenu(
    const TextManager &textManager,
    const FontManager &fontManager):
        mLogoText(),
        mPlayText(),
        mQuitText(),
        mMenuChoice(MenuChoice::Play)
{
    const sf::Font &logoFont = fontManager.get(FontId::Default);
    const sf::Font &menuFont = fontManager.get(FontId::Menu);
    const std::string &logoText = textManager.get(TextId::Logo).get();

    const auto setOrigin = [](sf::Text &t) {
        const sf::FloatRect sz = t.getLocalBounds();
        t.setOrigin(sz.width/2.0, sz.height/2.0);
    };

    mLogoText.setFont(logoFont);
    mLogoText.setCharacterSize(20);
    mLogoText.setString(logoText);
    mLogoText.setFillColor(sf::Color::Red);
    setOrigin(mLogoText);

    mPlayText.setFont(menuFont);
    mPlayText.setCharacterSize(60);
    mPlayText.setString("Play");
    setOrigin(mPlayText);


    mQuitText.setFont(menuFont);
    mQuitText.setCharacterSize(60);
    mQuitText.setString("Quit");
    setOrigin(mQuitText);
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

    const auto nextY = [](const sf::Text &t) {
        const sf::FloatRect sz = t.getGlobalBounds();
        const float spacing = 40.0f;
        return sz.top + sz.height + spacing;
    };

    mPlayText.setPosition(pos.x, nextY(mLogoText));
    mQuitText.setPosition(pos.x, nextY(mPlayText));

    mPlayText.setStyle(sf::Text::Regular);
    mQuitText.setStyle(sf::Text::Regular);

    switch (mMenuChoice)
    {
        case MenuChoice::Play: mPlayText.setStyle(sf::Text::Underlined); break;
        case MenuChoice::Quit: mQuitText.setStyle(sf::Text::Underlined); break;
    }

    window.draw(mLogoText);
    window.draw(mPlayText);
    window.draw(mQuitText);
}

void StartMenu::select(
    entityx::EventManager &eventManager)
{
    switch (mMenuChoice)
    {
        case MenuChoice::Play: eventManager.emit<StartGameEvent>(); break;
        case MenuChoice::Quit: eventManager.emit<QuitGameEvent>();  break;
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

    /* This is overkill for just two choices. If we add more, it'll be easy. */
    switch (mMenuChoice)
    {
        case MenuChoice::Play: mMenuChoice = MenuChoice::Quit; break;
        case MenuChoice::Quit: mMenuChoice = MenuChoice::Play; break;
    }
}

void StartMenu::down(
    entityx::EventManager &eventManager)
{
    (void)eventManager;
    switch (mMenuChoice)
    {
        case MenuChoice::Play: mMenuChoice = MenuChoice::Quit; break;
        case MenuChoice::Quit: mMenuChoice = MenuChoice::Play; break;
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
