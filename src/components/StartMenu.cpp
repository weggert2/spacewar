/**
 * @file
 *
 * $Id: StartMenu.cpp $
 * @author Bill Eggert
 */

#include "StartMenu.hpp"

#include "Events.hpp"
#include "Game.hpp"
#include "GameManager.hpp"

StartMenu::StartMenu(
    const std::wstring &logoText,
    const sf::Font &logoFont,
    const sf::Font &menuFont,
    const GameManager &gameManager,
    const int logoFontSize):
        mLogoText(),
        mPlayText(),
        mScoresText(),
        mCreditsText(),
        mQuitText(),
        mMenuChoice(MenuChoice::Play),
        mGameManager(gameManager)
{
    const auto setOrigin = [](sf::Text &t) {
        const sf::FloatRect sz = t.getLocalBounds();
        t.setOrigin(sz.width/2.0f, sz.height/2.0f);
    };

    mLogoText.setFont(logoFont);
    mLogoText.setCharacterSize(logoFontSize);
    mLogoText.setString(logoText);
    mLogoText.setFillColor(sf::Color::Red);
    setOrigin(mLogoText);

    const auto initMenu = [&](sf::Text &t, const std::string &s) {
        t.setFont(menuFont);
        t.setCharacterSize(35);
        t.setString(s);
        setOrigin(t);
    };

    initMenu(mPlayText,     "Play");
    initMenu(mControlsText, "Controls");
    initMenu(mScoresText,   "Scores");
    initMenu(mCreditsText,  "Credits");
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

    const auto nextY = [](const sf::Text &t, const float spacing = 20.0f) {
        const sf::FloatRect sz = t.getGlobalBounds();
        return sz.top + sz.height + spacing;
    };

    mPlayText.setPosition(pos.x,     nextY(mLogoText));
    mControlsText.setPosition(pos.x, nextY(mPlayText, 10.0f));
    mScoresText.setPosition(pos.x,   nextY(mControlsText));
    mCreditsText.setPosition(pos.x,  nextY(mScoresText, 25.0f));
    mQuitText.setPosition(pos.x,     nextY(mCreditsText, 30.0f));

    mPlayText.setStyle(sf::Text::Regular);
    mControlsText.setStyle(sf::Text::Regular);
    mScoresText.setStyle(sf::Text::Regular);
    mCreditsText.setStyle(sf::Text::Regular);
    mQuitText.setStyle(sf::Text::Regular);

    switch (mMenuChoice)
    {
        case MenuChoice::Play:     mPlayText.setStyle(sf::Text::Underlined);     break;
        case MenuChoice::Controls: mControlsText.setStyle(sf::Text::Underlined); break;
        case MenuChoice::Scores:   mScoresText.setStyle(sf::Text::Underlined);    break;
        case MenuChoice::Credits:  mCreditsText.setStyle(sf::Text::Underlined);  break;
        case MenuChoice::Quit:     mQuitText.setStyle(sf::Text::Underlined);     break;
    }

    window.draw(mLogoText);
    window.draw(mPlayText);
    window.draw(mControlsText);
    window.draw(mScoresText);
    window.draw(mCreditsText);
    window.draw(mQuitText);
}

void StartMenu::select(
    entityx::EventManager &eventManager)
{
    switch (mMenuChoice)
    {
        case MenuChoice::Play:     resumeGame(eventManager); break;
        case MenuChoice::Quit:     eventManager.emit<QuitGameEvent>();     break;
        case MenuChoice::Controls: eventManager.emit<ShowControlsEvent>(); break;
        case MenuChoice::Scores:   eventManager.emit<ShowScoresEvent>();   break;
        case MenuChoice::Credits:  eventManager.emit<ShowCreditsEvent>();  break;
    }

    eventManager.emit<PlaySoundEvent>(SoundId::MenuSelect);
}

void StartMenu::cancel(
    entityx::EventManager &eventManager)
{
    eventManager.emit<ResumeGameEvent>();
}

void StartMenu::up(
    entityx::EventManager &eventManager)
{
    (void)eventManager;

    const auto it = std::find(choices.begin(), choices.end(), mMenuChoice);
    int pos = std::distance(choices.begin(), it) - 1;
    if (pos < 0) pos = choices.size() - 1;
    mMenuChoice = choices[pos];

    eventManager.emit<PlaySoundEvent>(SoundId::MenuScroll);
}

void StartMenu::down(
    entityx::EventManager &eventManager)
{
    (void)eventManager;

    const auto it = std::find(choices.begin(), choices.end(), mMenuChoice);
    const int pos = std::distance(choices.begin(), it);
    mMenuChoice = choices[(pos+1)%choices.size()];

    eventManager.emit<PlaySoundEvent>(SoundId::MenuScroll);
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

void StartMenu::resumeGame(
    entityx::EventManager &eventManager)
{
    switch (mGameManager.getGameState())
    {
        case GameState::StartMenu:
        case GameState::GameOver:  eventManager.emit<StartGameEvent>();  break;

        case GameState::Playing:   /* Do nothing */                      break;

        case GameState::Controls:
        case GameState::Scores:
        case GameState::Paused:    eventManager.emit<ResumeGameEvent>(); break;
    }
}
