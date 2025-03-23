#include "Menu.h"

int Menu::update()
{
	hideCursor();
	while(1)
	{
		system("cls");
		print();
		moveCursor();
	}
}

int Menu::addElement(Label obj)
{
	labels.push_back(obj);
	return 0;
}

int Menu::addElement(Button obj)
{
	buttons.push_back(obj);
	return 0;
}

//std::deque <Student> exit(std::deque <Student>)
//{
//
//}
//
//int Menu::addExit()
//{
//	buttons.push_back();
//}

int Menu::print()
{
	int i = 0;
	HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);

	for (Label& elem : labels)
		elem.print();

	for (Button& elem : buttons)
	{
		SetConsoleTextAttribute(handler, 8);
		if (i == cursor)
			SetConsoleTextAttribute(handler, 15);
		elem.print();
		i++;
	}	

	SetConsoleTextAttribute(handler, 15);
	return 0;
}

int Menu::hideCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = FALSE;  // Скрываем курсор
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	return 0;
}

int Menu::moveCursor()
{
	int i = (int)_getch();

	switch (i)
	{
	case 80:
		++cursor;
		if (cursor >= buttons.size()) cursor = 0;
		break;
	case 72:
		--cursor;
		if (cursor < 0) cursor = buttons.size() - 1;
		break;
	case 13:
		execute();
		break;
	case 0 || 0xE0: 
		moveCursor();
	default:
		break;
	}

	return 0;
}

int Menu::execute()
{
	for (std::deque <Button> :: iterator iter = buttons.begin(); iter != buttons.end(); ++iter)
	{
		if(!cursor)
		{
			system("cls");
			objects = iter->callFunction(objects);
			break;
		}
		--cursor;
	}
	return 0;
}

Menu::Menu()
{
	cursor = 0;
}

Menu::Menu(Data _objects)
{
	objects = _objects;
	cursor = 0;
}

Menu::~Menu()
{

}