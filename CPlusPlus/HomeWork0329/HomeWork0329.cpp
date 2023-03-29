#include <iostream>
#include "ConsoleGameScreen.h"
#include "ConsoleGameMath.h"
#include "Player.h"
#include "Bullet.h"

int main()
{
	Bullet NewBullet = Bullet();
	Player NewPlayer = Player(&NewBullet);
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
			NewBullet.SetFire(true);
			NewBullet.BulletMove();
		}

		if (true == NewBullet.IsFire())
		{
			ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewBullet.GetPos(), 'o');
		}
		else if (false == NewBullet.IsFire())
		{
			NewPlayer.SetFire(false);
			NewBullet.SetPos(NewPlayer.GetPos());
		}

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
	}
}
