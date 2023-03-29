#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>

Bullet::Bullet()
{

}

void Bullet::SetPos(const ConsoleGameMath& _Value)
{
	Pos = _Value;
}

ConsoleGameMath Bullet::GetPos() const
{
	return Pos;
}

inline void Bullet::SetYPos(const int _Y)
{
	Pos.Y = _Y;
}

inline int Bullet::GetYPos() const
{
	return Pos.Y;
}

bool Bullet::IsFire()
{
	return Fire;
}

void Bullet::SetFire(const bool _Fire)
{
	Fire = _Fire;
}

void Bullet::BulletMove()
{
	ConsoleGameMath NextPos = Pos;
	NextPos.Y -= 1;
	if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
	{
		Pos.Y -= 1;
	}
	else
	{
		Fire = false;
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, 'a');
	}
}