#ifndef BUTTON
#define BUTTON

#include "Label.h"
#include "Student.h"
#include <functional>


class Button :
	public Label
{
public:
	using Function = std::deque <Student>(*) (std::deque <Student>);

	std::deque <Student> callFunction(std::deque <Student> obj) { return func(obj); };

	Button(Function _func) : func(_func) {};
	Button(short _x, short _y, std::string _name, Function _func) : Label(_x, _y, _name), func(_func) {};

private:
	Function func;
};

#endif // !BUTTON
