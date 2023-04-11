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

	++BombCount;
	if (step > Power + 1)
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

	if (5 < BombCount)
	{
		for (int i = 0; i < step; i++)
		{
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X - i, Pos.Y }, RenderChar);
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X + i, Pos.Y }, RenderChar);
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X, Pos.Y }, RenderChar);
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X, Pos.Y - i }, RenderChar);
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter({ Pos.X, Pos.Y + i }, RenderChar);
		}

		++step;
	}
}