/**
 * @file
 *
 * $Id: PlayerScoreSystem.hpp $
 * @author Bill Eggert
 */

#pragma once

#include "Events.hpp"

#include <entityx/Entity.h>
#include <entityx/System.h>

class PlayerScoreSystem : public entityx::System<PlayerScoreSystem>,
                          public entityx::Receiver<PlayerScoreSystem>
{
public:
    explicit PlayerScoreSystem(
        entityx::EventManager &eventManager);

    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);

    const std::wstring &getScores() const;

    void receive(const LoseGameEvent &event);
    void receive(const WinGameEvent &event);
    void receive(const StartGameEvent &event);
    void receive(const EnemyDestroyedEvent &event);
    void receive(const PauseGameEvent &event);
    void receive(const ResumeGameEvent &event);
    void updateHighScores();

private:
    entityx::EventManager &mEventManager;
    bool mShouldUpdate;
    float mScore;

    /* String storage */
    std::wstring mScoreStr;

    static constexpr size_t mMaxNumScores = 9u;
};
