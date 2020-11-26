#pragma once

#include <entityx/Entity.h>

class MenuBase;

class Menu : public entityx::Component<Menu>
{
public:
    explicit Menu(
        const MenuBase *menu);

private:
    MenuBase *mMenu;
};
