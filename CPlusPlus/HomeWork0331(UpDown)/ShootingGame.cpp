#include "ShootingGame.h"

#include <iostream>

// 내가 만든건 ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;
Monster* MonsterArr = Monster::GetArrMonster();

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