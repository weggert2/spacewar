#pragma once

#include "AssetManager.hpp"

#include <entityx/Entity.h>

class GameManager;

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
        const std::wstring &logoText,
        const sf::Font &logoFont,
        const sf::Font &menuFont,
        const GameManager &gameManager,
        const int logoFontSize = 20);

    virtual void create(
        entityx::Entity entity) override final;

private:
    const std::wstring &mLogoText;
    const sf::Font &mLogoFont;
    const sf::Font &mMenuFont;
    const GameManager &mGameManager;
    const int mLogoFontSize;
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

/*
 * Bullet creator
 */
class ProjectileCreator : public EntityCreator
{
public:
    struct TextureInfo
    {
        TextureId mTextureId;
        float mScaleX;
        float mScaleY;
        float mOrigX;
        float mOrigY;
    };

    ProjectileCreator(
        const TextureManager &textureManager,
        const TextureInfo &textureInfo,
        const sf::Vector2f &initialPos,
        const float initialAngle);

    virtual void create(
        entityx::Entity) override final;

private:
    const TextureManager &mTextureManager;
    const TextureInfo mTextureInfo;
    const sf::Vector2f mInitialPos;
    const float mInitialAngle;
};
