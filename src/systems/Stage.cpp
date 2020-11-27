#include "Stage.hpp"

Stage::Stage(
    const TextureManager &textureManager,
    entityx::EntityManager &entityManager,
    entityx::EventManager &eventManager):
        mTextureManager(textureManager),
        mEntityManager(entityManager),
        mEventManager(eventManager),
        mStage(0u)
{
    subscribeEvents();
}

void Stage::subscribeEvents()
{
    mEventManager.subscribe<StartGameEvent>(*this);
    mEventManager.subscribe<StageClearedEvent>(*this);
}

void Stage::update(
    entityx::EntityManager &entities,
    entityx::EventManager &events,
    const double dt)
{
    /* Nothing needed, I think? */
    (void)entities;
    (void)events;
    (void)dt;
}

void Stage::receive(
    const StartGameEvent &event)
{
    /* Make the background. */
    BackgroundCreator(mTextureManager).create(mEntityManager.create());
}

void Stage::receive(
    const StageClearedEvent &event)
{

}

