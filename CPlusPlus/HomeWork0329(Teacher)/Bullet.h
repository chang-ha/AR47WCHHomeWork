#pragma once
#include "ConsoleGameMath.h"

class Bullet
{
public:
	Bullet();

	void SetPos(const ConsoleGameMath& _Value);
	
	ConsoleGameMath GetPos() const;

	void Update();
protected:

private:
	ConsoleGameMath Pos = ConsoleGameMath(0, 0);
};

