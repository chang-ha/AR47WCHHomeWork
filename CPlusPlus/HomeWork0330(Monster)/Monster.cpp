#include "Monster.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "ConsoleGameMath.h"

Monster Monster::ArrMonster[Monster::ArrMonsterCount];

void Monster::SettingMonster()
{
	for (int i = 0; i < ArrMonsterCount; i++)
	{
		if (i % 2 == 0)
		{
			ArrMonster[i].SetPos({ 2 * i + 1, 0 });
		}
		else
		{
			ArrMonster[i].SetPos({ 2 * i + 1, 1 });
		}
	}
}

void Monster::AllRender()
{
	for (size_t i = 0; i < Monster::ArrMonsterCount; i++)
	{
		if (true == ArrMonster[i].Dead)
		{
			continue;
		}
		ArrMonster[i].Render();
	}

}

void Monster::AllUpdate()
{
	for (size_t i = 0; i < Monster::ArrMonsterCount; i++)
	{
		ArrMonster[i].Update();
	}
}


void Monster::Render()
{
	if (true == Dying)
	{
		Dead = true;
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, 'X');
	}
	else if (false == Dead)
	{
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, 'M');
	}
}

void Monster::Update()
{
	if (true == Monster::HitBullet())
	{
		Monster::Dying = true;
	}
}

bool Monster::HitBullet()
{
	if (ConsoleGameScreen::GetMainScreen().GetScreenCharacter(Pos) == '^')
	{
		return true;
	}
	return false;
}

Monster::Monster()
{

}