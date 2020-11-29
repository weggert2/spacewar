/**
 * @file
 *
 * $Id: MusicSystem.hpp $
 * @author Bill Eggert
 */

#pragma once

#include "AssetManager.hpp"
#include "Events.hpp"

#include <entityx/Entity.h>
#include <entityx/System.h>

class MusicSystem : public entityx::System<MusicSystem>,
                    public entityx::Receiver<MusicSystem>
{
public:
    MusicSystem(
        MusicManager &musicManager,
        entityx::EventManager &eventManager);

    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);

    void receive(const LaunchGameEvent &event);
    void receive(const StartGameEvent &event);
    void receive(const PauseGameEvent &event);
    void receive(const ResumeGameEvent &event);
    void receive(const WinGameEvent &event);
    void receive(const LoseGameEvent &event);

private:
    void play(const MusicId id);

private:
    MusicManager &mMusicManager;
    MusicId mCurrId;
};
