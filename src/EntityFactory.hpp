#pragma once

#include <entityx/Entity.h>

class EntityCreator
{
public:
    virtual ~EntityCreator() = default;
    virtual void create(entityx::Entity entity) = 0;
};
