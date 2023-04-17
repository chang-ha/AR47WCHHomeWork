// HomeWork0414.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
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
