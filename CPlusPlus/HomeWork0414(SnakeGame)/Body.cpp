#include "Body.h"
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <list>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "GameEnum.h"
#include <conio.h>


Body::Body()
{
	RenderChar = 'I';
	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Half().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Half().Y - 1);
	SetPos({ X, Y });
}

Body::~Body()
{

}

void Body::Update()
{
	std::list<ConsoleGameObject*>& HeadGroup = ConsoleObjectManager::GetGroup(ObjectOrder::Head);
	ConsoleGameObject* Player = HeadGroup.front();
	if (true == PlayerEat && nullptr == Prev)
	{
		BeforePos = GetPos();
		SetPos(Player->GetPos());
	}
	else if (true == PlayerEat && nullptr != Prev)
	{
		BeforePos = GetPos();
		SetPos(Prev->GetBeforePos());
	}
	else if (nullptr == Prev)
	{
		return;
	}
}

void Body::Death()
{
	PlayerEat = true;
	RenderChar = 'O';
	if (nullptr != Prev)
	{
		SetPos(Prev->GetBeforePos());
	}
	Body* NewBody = ConsoleObjectManager::CreateConsoleObject<Body>(ObjectOrder::Body);
	NewBody->Prev = this;
	Next = NewBody;
	NewBody->CreateBody();
}

bool Body::IsPlayerEat()
{
	return PlayerEat;
}

void Body::CreateBody()
{
	std::vector<int2> Map;
	int2 MapSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	int2 MapPos = { 0,0 };
	Map.reserve(MapSize.X * MapSize.Y);

	for (int y = 0; y < MapSize.Y; y++)
	{
		for (int x = 0; x < MapSize.X; x++)
		{
			MapPos = { x, y };
			char temp = ConsoleGameScreen::GetMainScreen().GetScreenCharacter(MapPos);
			if (temp == 'a')
			{
				Map.push_back(MapPos);
			}
		}
	}

	if (0 == Map.size())
	{
		system("cls");
		printf_s("%s\n", "You Win");
		exit(0);
	}

	int Index = GameEngineRandom::MainRandom.RandomInt(0, Map.size() - 1);
	this->SetPos(Map[Index]);
}