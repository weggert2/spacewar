/**
 * @file
 *
 * $Id: ProjectileDurationSystem.cpp $
 * @author Bill Eggert
 */

#pragma once

#include <entityx/System.h>

class ProjectileDurationSystem : public entityx::System<ProjectileDurationSystem>
{
public:
    ProjectileDurationSystem() = default;

    void update(
        entityx::EntityManager &entities,
        entityx::EventManager &events,
        const double dt);
};
