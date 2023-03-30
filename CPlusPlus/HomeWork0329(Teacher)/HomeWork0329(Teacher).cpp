#include <iostream>
#include "ConsoleGameScreen.h"
#include "ConsoleGameMath.h"
#include "Player.h"
#include "Bullet.h"

int main()
{
	Bullet NewBullet = Bullet();
	Player NewPlayer = Player();
	ConsoleGameMath ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());
	NewBullet.SetPos(NewPlayer.GetPos());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.GetPos(), '*');

		if (true == NewPlayer.IsFire())
		{
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewBullet.GetPos(), 'O');
			NewBullet.Update();
		}
		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
	}
}
