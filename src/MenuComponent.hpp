#pragma once

#include <entityx/Entity.h>

class Menu;

class MenuComponent : public entityx::Component<MenuComponent>
{
public:
    explicit MenuComponent(
        const Menu *menu);

private:
    Menu *mMenu;
};
