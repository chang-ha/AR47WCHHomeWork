#pragma once
#include "ConsoleGameMath.h"

class Bullet;
class Player
{
public:
	Player();
	Player(Bullet* _NewBullet);

	void SetPos(const ConsoleGameMath& _Value);

	ConsoleGameMath GetPos() const;

	void Input();

	bool IsFire() const;

	void SetFire(bool _Fire);

protected:

private:
	static const int InterFrame = 200;

	ConsoleGameMath Pos = ConsoleGameMath(0, 0);

	bool Fire = false;

	Bullet* NewBullet= nullptr;
};

