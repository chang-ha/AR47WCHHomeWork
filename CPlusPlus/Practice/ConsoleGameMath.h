#pragma once

class ConsoleGameMath
{
public:
	// constructer destructer
	ConsoleGameMath();
	ConsoleGameMath(int _X, int _Y);
	~ConsoleGameMath();

	// delete function
	ConsoleGameMath(const ConsoleGameMath& _Ohter) = delete;
	ConsoleGameMath(ConsoleGameMath&& _Ohter) noexcept = delete;
	ConsoleGameMath& operator=(const ConsoleGameMath& _Other) = delete;
	ConsoleGameMath& operator=(ConsoleGameMath&& _Other) noexcept = delete;

	ConsoleGameMath& GetPos();
	ConsoleGameMath& Half();
	int GetPosX();
	int GetPosY();

protected:

private:
	int X;
	int Y;
};

