#include "Student.h"

std::deque <Student> printAll(std::deque <Student> beg)
{
	for (const Student& elem : beg) std::cout << elem << std::endl;
	_getch();
	return beg;
}

std::deque <Student> addAnother(std::deque <Student> beg)
{
	Student elem;

	std::cin >> elem;

	beg.push_back(elem);

	return beg;
}

std::deque <Student> sorting(std::deque <Student> beg)
{
	auto predicator{ [] (const Student& beg1, const Student& beg2) { return beg1 > beg2; } };
	std::sort(beg.begin(), beg.end(), predicator);
	return beg;
}

std::deque <Student> save(std::deque <Student> beg)
{
	std::ofstream file("tests.txt", std::ios::binary);

	if (!file.is_open()) return beg;

	for (const Student& elem : beg)
	{
		file << elem;
	}

	file.close();
	_getch();

	return beg;
}

std::deque <Student> load(std::deque <Student> beg)
{
	Student elem;

	std::ifstream file("tests.txt", std::ios::binary);

	if (!file.is_open()) return beg;

	while (file >> elem)
	{
		beg.push_front(elem);
	}

	file.close();
	_getch();

	return beg;
}

std::deque <Student> search(std::deque <Student> beg)
{
	Student person;
	std::deque <Student> ::iterator it;

	std::cout << "Input who we searching for" << std::endl;
	std::cin >> person;
	it = std::find(beg.begin(), beg.end(), person);

	if (it != beg.end())
		std::cout << "he/she is in our data base!";
	else
		std::cout << "he/she isn't in our data base!";

	_getch();

	return beg;
}

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
	std::cout << "Input ID: " << std::endl;
	os >> beg.ID;
	std::cout << "Input Marks (HM, IT, ORG): " << std::endl;
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