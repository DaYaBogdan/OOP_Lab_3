#ifndef MENU
#define MENU
#include "Button.h"

#include <conio.h>

class Menu
{
public:
	Menu(std::deque <Student> _beg);
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

	std::deque <Student> beg;
	std::deque <Label> labels;
	std::deque <Button> buttons;
};

#endif