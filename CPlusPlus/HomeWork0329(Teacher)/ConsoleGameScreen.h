#pragma once
#include "ConsoleGameMath.h"

// �̰� 1�ܰ�
// �ٺ����� �ٺ� ���� ���� 
class ConsoleGameScreen
{
public:
	// Ŭ���� ���ο� ���������� �����Ҽ��� �ֽ��ϴ�.
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