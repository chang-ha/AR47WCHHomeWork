#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];


void Bullet::AllRender() 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsFire())
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
		if (false == ArrBullet[i].IsFire())
		{
			continue;
		}
		ArrBullet[i].Update(i%3);
	}
}

Bullet::Bullet()
{

}

void Bullet::Render()
{
	if (true == Fire)
	{
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '^');
	}
}

void Bullet::Update(int _Value) 
{
	if (true == Fire)
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