#include "Student.h"

bool operator != (const Student& obj1, const Student& obj2)
{
	return !(obj1 == obj2);
}

bool operator == (const Student& obj1, const Student& obj2)
{
	return (obj1.ID == obj2.ID) && (obj1.mark.HM == obj2.mark.HM) && obj1.mark.IT == obj2.mark.IT && obj1.mark.ORG == obj2.mark.ORG;
}

bool operator < (const Student& obj1, const Student& obj2)
{
	return obj1.ID < obj2.ID;
}

bool operator > (const Student& obj1, const Student& obj2)
{
	return obj1.ID > obj2.ID;
}

std::ostream& operator << (std::ostream& os, const Student& beg)
{
	return os << beg.ID << " " << beg.mark.HM << " " << beg.mark.IT << " " << beg.mark.ORG;
}

std::istream& operator >> (std::istream& os, Student& beg)
{
	os >> beg.ID;

	os >> beg.mark.HM >> beg.mark.IT >> beg.mark.ORG;
	return os;
}

Student::Student()
{
	ID = 0;
	mark.HM = 2;
	mark.IT = 2;
	mark.ORG = 2;
}

Student::Student(int _ID, marks _mark)
{
	ID = _ID;
	mark = _mark;
}

Student::~Student()
{

}