#include "Bomb.h"


Bomb::Bomb()
{
	RenderChar = '@';
}

Bomb::~Bomb()
{

}

void Bomb::Update()
{
	ConsoleGameObject::Update();

	if (0 >= --BombCount)
	{
		Off();
	}
}

void Bomb::Render()
{
	ConsoleGameObject::Render();
	if (false == IsUpdate())
	{
		return;
	}

	if (4 >= BombCount)
	{
		for (int x = 0; x < 5; x++)
		{
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X + x - 2, Pos.Y }, RenderChar);
		}
		for (int y = 0; y < 5; y++)
		{
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X, Pos.Y + y - 2 }, RenderChar);
		}
	}
	else if (7 >= BombCount)
	{
		for (int x = 0; x < 3; x++)
		{
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X + x - 1, Pos.Y }, RenderChar);
		}
		for (int y = 0; y < 3; y++)
		{
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X, Pos.Y + y - 1 }, RenderChar);
		}
	}
}