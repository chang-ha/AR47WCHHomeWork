#pragma once
#include "ConsoleGameMath.h"

class Bullet
{
public:
	Bullet();

	void SetPos(const ConsoleGameMath& _Value);
	
	ConsoleGameMath GetPos() const;

	inline void SetYPos(const int _Y);

	inline int GetYPos() const;

	bool IsFire() const ;

	void SetFire(const bool _Fire);

	void BulletMove();
protected:

private:
	bool Fire = false;
	ConsoleGameMath Pos = ConsoleGameMath(0, 0);
};

