#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen;
class Player
{
public:
	Player();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	void Input();

	void Render();

	void SetBulletArr(class Bullet* _BulletPtr)
	{
		BulletPtr = _BulletPtr;
	}

protected:

private:
	static const int InterFrame = 200;

	int NowBullet = 0;

	int2 Pos = int2(0, 0);

	Bullet* BulletPtr = nullptr;
};

