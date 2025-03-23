#include "MasterHeader.h"

Menu menuCreate()
{
    Data beg;

    Menu menu = {beg};

    menu.addElement({6, 9, "Menu"});
    menu.addElement({6, 10, "PrintAll", printAll});
    menu.addElement({6, 11, "AddAnother", addAnother });
    menu.addElement({6, 12, "Save", save});
    menu.addElement({6, 13, "Load", load});
    menu.addElement({6, 14, "Sort", sorting});
    menu.addElement({6, 15, "Search", search});

    return menu;
}


int main() 
{
    Menu menu = menuCreate();

    menu.update();

    return 0;
}