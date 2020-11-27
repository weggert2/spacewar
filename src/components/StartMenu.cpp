#include "StartMenu.hpp"

StartMenu::StartMenu(
    const TextManager &textManager,
    const FontManager &fontManager)
{
    const sf::Font &logoFont = fontManager.get(FontId::Default);
    const sf::Font &menuFont = fontManager.get(FontId::Menu);

    const std::string &logoText = textManager.get(TextId::Logo).get();

    mLogoText.setFont(logoFont);
    mLogoText.setCharacterSize(20);
    mLogoText.setString(logoText);
    mLogoText.setFillColor(sf::Color::Red);



    // sf::Text mLogoText;
    // sf::Text mPlayText;
    // sf::Text mQuitText;
}

void StartMenu::draw(
    sf::RenderWindow &window,
    const sf::Vector2f &pos)
{
    mLogoText.setPosition(pos);
    window.draw(mLogoText);
}
