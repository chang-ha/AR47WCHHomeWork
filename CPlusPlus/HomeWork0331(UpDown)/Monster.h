#pragma once
#include "ConsoleGameObject.h"
#include "ConsoleGameScreen.h"

class Monster : public ConsoleGameObject
{
public:
	static const int ArrMonsterCount = 10;

	static Monster* GetArrMonster()
	{
		return ArrMonster;
	}

	static void ChangeXDirect()
	{
		DirX = -DirX;
	}

	static void ChangeYDirect()
	{
		DirY = -DirY;
	}

	void Monster_Setting();

	void Update();

	void AllUpdate();

	void AllRender();
	
	void MoveRightLeft();

	void MoveUpDown();

private:
	static Monster ArrMonster[ArrMonsterCount];

	Monster();

	static int DirX;

	static int DirY;
};

