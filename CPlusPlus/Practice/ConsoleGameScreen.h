#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen
{
public:

	// constructer destructer
	ConsoleGameScreen();
	~ConsoleGameScreen();

	// delete function
	ConsoleGameScreen(const ConsoleGameScreen& _Ohter) = delete;
	ConsoleGameScreen(ConsoleGameScreen&& _Ohter) noexcept = delete;
	ConsoleGameScreen& operator=(const ConsoleGameScreen& _Other) = delete;
	ConsoleGameScreen& operator=(ConsoleGameScreen&& _Other) noexcept = delete;

protected:

private:

	ConsoleGameMath Pos;
};

