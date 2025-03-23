#ifndef MENU
#define MENU
#include "Button.h"
#include "Data.h"
#include <conio.h>

class Menu
{
public:
	Menu(Data _objects);
	Menu();
	~Menu();

	int update();

	int addElement(Label obj);
	int addElement(Button obj);
	int addExit();

	int print();

	int hideCursor();
	int moveCursor();

	int execute();

private:

	int cursor;

	Data objects;
	std::deque <Label> labels;
	std::deque <Button> buttons;
};

#endif