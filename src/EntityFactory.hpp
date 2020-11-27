#pragma once

#include "AssetManager.hpp"

#include <entityx/Entity.h>

class EntityCreator
{
public:
    virtual ~EntityCreator() = default;
    virtual void create(entityx::Entity entity) = 0;
};

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
