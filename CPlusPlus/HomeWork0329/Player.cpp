#include "Player.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
Player::Player()
{

}
Player::Player(Bullet* _NewBullet)
	: NewBullet(_NewBullet)
{

}

void Player::SetPos(const ConsoleGameMath& _Value)
{
	Pos = _Value;
}

ConsoleGameMath Player::GetPos() const
{
	return Pos;
}

bool Player::IsFire() const
{
	return Fire;
}

void Player::SetFire(bool _Fire)
{
	Fire = _Fire;
}

void Player::Input()
{
	if (0 == _kbhit())
	{
		Sleep(InterFrame);
		return;
	}

	char Ch = _getch();

	ConsoleGameMath NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'x':
	case 'X':
		if (NewBullet == nullptr)
		{
			break;
		}
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Player::SetFire(true);
		}
		break;
	default:
		break;
	}

	Sleep(InterFrame);
}
