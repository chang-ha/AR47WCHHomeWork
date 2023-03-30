#pragma once
class ConsoleGameMath
{
public:
	inline ConsoleGameMath()
	{

	}
	inline ConsoleGameMath(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}
	int X = 0;
	int Y = 0;

	inline ConsoleGameMath Half()
	{
		return { X / 2, Y / 2 };
	}

protected:

private:


};

