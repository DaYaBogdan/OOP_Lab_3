#ifndef OBJECT
#define OBJECT
#include <iostream>
#include <windows.h>

class Object
{
public:
	Object();
	Object(short x, short y);
	~Object();

	int GoToXY();

private:
	short x;
	short y;
};

#endif // !OBJECT