#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];

void Bullet::AllOff()
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		ArrBullet[i].Off();
	}
}

void Bullet::AllRender() 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsUpdate())
		{
			continue;
		}

		ArrBullet[i].Render();
	}
}

void Bullet::AllUpdate() 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsUpdate())
		{
			continue;
		}

		ArrBullet[i].Update(i%3);
	}
}

Bullet::Bullet()
{
	RenderChar = '^';
}


void Bullet::Update(int _Value)
{
	if (true == IsUpdate())
	{
		if (_Value == 0)
		{
			--Pos.X;
			--Pos.Y;
		}
		else if (_Value == 1)
		{
			--Pos.Y;
		}
		else if (_Value == 2)
		{
			++Pos.X;
			--Pos.Y;
		}
	}
}