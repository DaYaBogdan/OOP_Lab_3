#ifndef BUTTON
#define BUTTON

#include "Label.h"
#include "Data.h"


class Button :
	public Label
{
public:
	using Function = Data(*) (Data);

	Data callFunction(Data obj) const { return func(obj); };

	Button(Function _func) : func(_func) {};
	Button(short _x, short _y, std::string _name, Function _func) : Label(_x, _y, _name), func(_func) {};

private:
	Function func;
};

#endif // !BUTTON
