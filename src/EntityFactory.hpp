#pragma once

#include "AssetManager.hpp"

#include <entityx/Entity.h>

/*
 * Base class for Entities.
 */
class EntityCreator
{
public:
    virtual ~EntityCreator() = default;
    virtual void create(entityx::Entity entity) = 0;
};

/*
 * Start menu creator.
 */
class StartMenuCreator : public EntityCreator
{
public:
    StartMenuCreator(
        const TextManager &textManager,
        const FontManager &fontManager);

    virtual void create(
        entityx::Entity entity) override final;

private:
    const TextManager &mTextManager;
    const FontManager &mFontManager;
};

/*
 * Background creator.
 */
class BackgroundCreator : public EntityCreator
{
public:
    explicit BackgroundCreator(
        const TextureManager &textureManager);

    virtual void create(
        entityx::Entity entity) override final;

private:
    const TextureManager &mTextureManager;
};


/*
 * Player creator.
 */
class PlayerCreator : public EntityCreator
{
public:
    explicit PlayerCreator(
        const TextureManager &textureManager);

    virtual void create(
        entityx::Entity entity) override final;

private:
    const TextureManager &mTextureManager;
};

/*
 * Enemy creator.
 */
class EnemyCreator : public EntityCreator
{
public:
    explicit EnemyCreator(
        const TextureManager &textureManager,
        const sf::Vector2f &initialPos,
        const float initialAngle);

    virtual void create(
        entityx::Entity entity) override final;

private:
    const TextureManager &mTextureManager;
    const sf::Vector2f mInitialPos;
    const float mInitialAngle;
};
