
#include <iostream>
#include <crtdbg.h>
#include "ConsoleGameMath.h"
#include "ConsoleGameArray.h"


int main()

{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ConsoleGameArray<ConsoleGameArray<char>> ChArr0(10);
	ChArr0.AllPrint();

}