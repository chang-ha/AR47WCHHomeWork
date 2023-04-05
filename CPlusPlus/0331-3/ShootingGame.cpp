#include "ShootingGame.h"

#include <iostream>
#include <conio.h>
// 내가 만든건 ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;

void ShootingGame::Loading()
{
	Bullet::AllOff();

	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();

	NewPlayer.SetPos(ScreenSize.Half());

	Monster::GetArrMonster()->Monster_Setting();
}

void ShootingGame::Collision()
{
	Bullet* BulletArr = Bullet::GetArrBullet();
	Monster* MonsterArr = Monster::GetArrMonster();

	for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
	{
		Bullet& CurBullet = BulletArr[BulletIndex];

		if (false == CurBullet.IsUpdate())
		{
			continue;
		}

		for (size_t MonsterIndex = 0; MonsterIndex < Monster::ArrMonsterCount; MonsterIndex++)
		{
			Monster& CurMonster = MonsterArr[MonsterIndex];

			if (false == CurMonster.IsUpdate())
			{
				continue;
			}

			if (CurMonster.GetPos() == CurBullet.GetPos())
			{
				CurMonster.Off();
				CurMonster.Death();
				CurBullet.Off();
			}
		}
	}
}

void ShootingGame::PlayerDeathCehck()
{
	Monster* MonsterArr = Monster::GetArrMonster();

	for (size_t MonsterIndex = 0; MonsterIndex < Monster::ArrMonsterCount; MonsterIndex++)
	{
		Monster& CurMonster = MonsterArr[MonsterIndex];
		if (CurMonster.GetPos() == NewPlayer.GetPos())
		{
			printf_s("---You Die---\n");
			printf_s("Press Any Key\n");
			char Ch = _getch();
			switch (Ch)
			{
			default:
				GameProgress();
				break;
			}
		}
	}
}

void ShootingGame::MonsterMove()
{
	Monster::GetArrMonster()->MoveRightLeft();

	Monster::GetArrMonster()->MoveUpDown();
}

void ShootingGame::GameUpdate()
{
	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// 캐릭터 위치에 글자를 하나 띄운다.
		NewPlayer.Render();
		Bullet::AllRender();
		Monster::GetArrMonster()->AllRender();

		MonsterMove();
		Collision();
		PlayerDeathCehck();
		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
		Monster::GetArrMonster()->AllUpdate();
	}
}

void ShootingGame::GameProgress()
{
	Loading();
	GameUpdate();
}