#pragma once
#include "ConsoleGameMath.h"

// 이게 1단계
// 근본오브 근본 수학 물리 
class ConsoleGameScreen
{
public:
	// 클래스 내부에 전역변수를 선언할수가 있습니다.
	static const int ScreenYSize = 5;
	static const int ScreenXSize = 5;

	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	static ConsoleGameMath GetScreenSize();

	void ScreenClear ();

	void ScreenPrint() const;

	bool IsScreenOver(const ConsoleGameMath& _Pos) const;

	void SetScreenCharacter(const ConsoleGameMath& _Pos, char _Ch);

protected:

private:
	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	ConsoleGameScreen();

	static ConsoleGameScreen MainScreen;
};