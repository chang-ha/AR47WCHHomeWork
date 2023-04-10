#include "ConsoleGameMath.h"


ConsoleGameMath::ConsoleGameMath()
	:X(0), Y(0)
{

}

ConsoleGameMath::ConsoleGameMath(int _X, int _Y)
	: X(_X), Y(_Y)
{

}

ConsoleGameMath::~ConsoleGameMath()
{

}

ConsoleGameMath& ConsoleGameMath::GetPos()
{
	return *this;
}

ConsoleGameMath& ConsoleGameMath::Half()
{
	X /= 2;
	Y /= 2;
	return *this;
}

int ConsoleGameMath::GetPosX()
{
	return X;
}

int ConsoleGameMath::GetPosY()
{
	return Y;
}
