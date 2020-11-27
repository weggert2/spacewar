#include "StartMenu.hpp"
#include "Game.hpp"

StartMenu::StartMenu(
    const TextManager &textManager,
    const FontManager &fontManager)
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
    mPlayText.setStyle(sf::Text::Underlined);
    setOrigin(mPlayText);


    mQuitText.setFont(menuFont);
    mQuitText.setCharacterSize(60);
    mQuitText.setString("Quit");
    setOrigin(mQuitText);
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

    window.draw(mLogoText);
    window.draw(mPlayText);
    window.draw(mQuitText);
}
