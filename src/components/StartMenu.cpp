#include "StartMenu.hpp"

StartMenu::StartMenu(
    const TextManager &textManager,
    const FontManager &fontManager)
{
    const auto logoFont = fontManager.get(FontId::Default);
    const auto menuFont = fontManager.get(FontId::Menu);

    const std::string &logoText = textManager.get(TextId::Logo).get();

    mLogoText.setFont(logoFont);
    mLogoText.setCharacterSize(10);
    mLogoText.setString(logoText);



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
