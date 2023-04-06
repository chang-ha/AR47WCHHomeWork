// HomeWork0407


#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineConsole/ConsoleGameScreen.h>

int main()
{
	while (true)
	{
		ConsoleGameScreen::GetMainScreen().ScreenClear();
		ConsoleGameScreen::GetMainScreen().ScreenPrint();
		Sleep(500);

	}
}