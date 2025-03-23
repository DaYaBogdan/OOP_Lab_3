#ifndef DATA
#define DATA

#include "Student.h"
#include <deque>
#include <fstream>
#include <conio.h>
#include <algorithm>

class Data
{
public:
	friend Data printAll(Data beg);
	friend Data addAnother(Data beg);
	friend Data sorting(Data beg);
	friend Data save(Data beg);
	friend Data load(Data beg);
	friend Data search(Data beg);

private:
	std::deque <Student> objectsList;
};

Data printAll(Data beg);
Data addAnother(Data beg);
Data sorting(Data beg);
Data save(Data beg);
Data load(Data beg);
Data search(Data beg);

#endif

