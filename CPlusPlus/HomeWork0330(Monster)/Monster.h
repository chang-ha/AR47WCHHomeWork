#pragma once
#include "ConsoleGameMath.h"
#include "ShootingGame.h"

class Monster
{
public:
	static const int ArrMonsterCount = 10;

	static Monster* GetArrMonster()
	{
		return ArrMonster;
	}

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}
	
	inline bool IsDead() const
	{
		return Dead;
	}

	void SettingMonster();

	static void AllRender();

	static void AllUpdate();

	void Render();

	void Update();

	bool HitBullet();

protected:

private:
	static Monster ArrMonster[ArrMonsterCount];

	Monster();

	bool Dead = false;

	bool Dying = false;

	int2 Pos = int2(0, 0);
};

