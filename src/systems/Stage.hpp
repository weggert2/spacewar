#pragma once

#include <entityx/System.h>

class Stage : public entityx::System<Stage>,
              public entityx::Receiver<Stage>
{
public:
    Stage(
        entityx::EntityManager &entityManager,
        entityx::EventManager &eventManager);

};
