#pragma once

/* Defines the events that can be emitted / received. */

#include <entityx/Entity.h>
#include <entityx/Event.h>

class StartGameEvent : public entityx::Event<StartGameEvent> {};
class QuitGameEvent  : public entityx::Event<QuitGameEvent>  {};
