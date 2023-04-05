#include "Monster.h"
#include "ConsoleGameScreen.h"

Monster Monster::ArrMonster[Monster::ArrMonsterCount];

int Monster::DirX = -1;
int Monster::DirY = +1;

Monster::Monster()
{
	RenderChar = 'M';
}

void Monster::Monster_Setting()
{
	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({ i + 3, 1 });
	}
}

void Monster::Update()
{
	if (false == IsUpdate())
	{
		return;
	}
}

void Monster::AllRender()
{
	for (size_t i = 0; i < Monster::ArrMonsterCount; i++)
	{
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

void Monster::MoveRightLeft()
{
	for (int i = 0; i < Monster::ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({ ArrMonster[i].GetPos().X + DirX, ArrMonster[i].GetPos().Y });
	}
}

void Monster::MoveUpDown()
{
	for (int i = 0; i < ArrMonsterCount; i++)
	{
		if (true == ArrMonster[i].IsDeath())
		{
			continue;
		}
		else if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(ArrMonster[i].GetPos()))
		{
			if (0 == ArrMonster[i].GetPos().Y || ConsoleGameScreen::ScreenYSize - 1 == ArrMonster[i].GetPos().Y)
			{
				ChangeYDirect();
			}
			for (int i = 0; i < ArrMonsterCount; i++)
			{
				ArrMonster[i].SetPos({ ArrMonster[i].GetPos().X - DirX , ArrMonster[i].GetPos().Y + DirY });
			}
			ChangeXDirect();
		}
	}
}
