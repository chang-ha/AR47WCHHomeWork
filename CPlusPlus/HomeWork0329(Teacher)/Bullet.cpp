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

void Bullet::Update()
{
	--Pos.Y;
}