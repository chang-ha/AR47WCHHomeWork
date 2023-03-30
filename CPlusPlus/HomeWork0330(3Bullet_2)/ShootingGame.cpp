#include <iostream>
#include "ShootingGame.h"
#include "Player.h"
#include "Bullet.h"
#include "ConsoleGameScreen.h"

void ShootingGame::GameProgress()
{
	Player NewPlayer = Player();

	NewPlayer.SetBulletArr(Bullet::GetArrBullet());
	
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	
	NewPlayer.SetPos(ScreenSize.Half());
	
	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();
		NewPlayer.Render();
		Bullet::AllRender();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();
		NewPlayer.Input();
		Bullet::AllUpdate();
	}
}