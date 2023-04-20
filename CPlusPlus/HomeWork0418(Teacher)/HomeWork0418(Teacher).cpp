// HomeWork0418


#include <iostream>
#include "GameEngineDebug.h"
#include "GameEngineRandom.h"
#include "ConsoleGameScreen.h"
#include "ConsoleGameObject.h"
#include "ConsoleObjectManager.h"
#include "Head.h"
#include "Body.h"
#include "GameEnum.h"
#include <conio.h>

int main()
{
	GameEngineDebug::LeckCheck();

	int2 ScreenSize = { 10, 5 };
	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);

	ConsoleObjectManager::CreateConsoleObject<Head>(SnakeGameOrder::Head);

	ConsoleObjectManager::CreateConsoleObject<Body>(SnakeGameOrder::Body);
	while (true == Head::IsPlay)
	{
		ConsoleObjectManager::ConsoleAllObjectUpdate();
		ConsoleObjectManager::ConsoleAllObjectRender();
		ConsoleObjectManager::ConsoleAllObjectRelease();
		Sleep(200);
	}

	ConsoleObjectManager::ConsoleAllObjectDelete();
}