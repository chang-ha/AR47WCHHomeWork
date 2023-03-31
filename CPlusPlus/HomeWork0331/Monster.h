#pragma once
#include "ConsoleGameObject.h"
#include "ConsoleGameScreen.h"

class Monster : public ConsoleGameObject
{
public:
	static void ChangeDirect()
	{
		if (Dir == 1)
		{
			Dir = -1;
		}
		else if (Dir == -1)
		{
			Dir = 1;
		}
	}

	static int GetDir()
	{
		return Dir;
	}
	
	void MoveDown()
	{
		--Pos.Y;
	}

	Monster();
	void Update();

private:
	static int Dir;
};

