#pragma once

#include <entityx/Entity.h>

class MenuBase;

class MenuComponent : public entityx::Component<MenuComponent>
{
public:
    explicit MenuComponent(
        MenuBase *menu);

private:
    MenuBase *mMenu;
};
