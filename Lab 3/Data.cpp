#include "Data.h"

Data printAll(Data beg)
{
	for (const Student& elem : beg.objectsList) std::cout << elem << std::endl;
	_getch();
	return beg;
}

Data addAnother(Data beg)
{
	Student elem;
	std::cout << "Input ID and Marks (HM, IT, ORG): " << std::endl;

	std::cin >> elem;

	beg.objectsList.push_back(elem);

	return beg;
}

Data sorting(Data beg)
{
	auto predicator{ [](const Student& beg1, const Student& beg2) { return beg1 > beg2; } };
	std::sort(beg.objectsList.begin(), beg.objectsList.end(), predicator);
	return beg;
}

Data save(Data beg)
{
	std::ofstream file("tests.txt", std::ios::binary);

	if (!file.is_open()) return beg;

	for (const Student& elem : beg.objectsList)
	{
		file << elem << std::endl;
	}

	file.close();
	_getch();

	return beg;
}

Data load(Data beg) //переработать
{
	Student elem;

	std::ifstream file("tests.txt", std::ios::binary);

	if (!file.is_open()) return beg;

	while (file >> elem)
	{
		beg.objectsList.push_front(elem);
	}

	file.close();
	_getch();

	return beg;
}

Data search(Data beg)
{
	Student person;
	std::deque <Student> :: iterator it;

	std::cout << "Input who we searching for" << std::endl;
	std::cin >> person;
	it = std::find(beg.objectsList.begin(), beg.objectsList.end(), person);

	if (it != beg.objectsList.end())
		std::cout << "he/she is in our data base!";
	else
		std::cout << "he/she isn't in our data base!";

	_getch();

	return beg;
}