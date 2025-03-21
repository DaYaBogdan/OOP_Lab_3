#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <deque>
#include <fstream>
#include <conio.h>
#include <algorithm>

struct marks
{
	int HM;
	int IT;
	int ORG;
};

class Student
{
public:

	friend bool operator != (const Student& obj1, const Student& obj2);
	friend bool operator == (const Student&, const Student&);
	friend bool operator < (const Student&, const Student&);
	friend bool operator > (const Student&, const Student&);
	friend std::ostream& operator << (std::ostream& os, const Student& beg);
	friend std::istream& operator >> (std::istream& os, Student& beg);

	Student();
	Student(int _ID, marks _mark);
	~Student();

private:
	int ID;
	marks mark;
};

std::deque <Student> printAll(std::deque <Student> beg);
std::deque <Student> addAnother(std::deque <Student> beg);
std::deque <Student> sorting(std::deque <Student> beg);
std::deque <Student> save(std::deque <Student> beg);
std::deque <Student> load(std::deque <Student> beg);
std::deque <Student> search(std::deque <Student> beg);


#endif // !STUDENT