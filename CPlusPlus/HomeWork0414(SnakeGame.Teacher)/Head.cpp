#include "Head.h"
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <list>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "GameEnum.h"
#include "Body.h"
#include <conio.h>
bool Head::IsPlay = true;

Head::Head()
{
	RenderChar = '$';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head()
{

}

void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*> BodyGroup = ConsoleObjectManager::GetGroup(SnakeGameOrder::Body);

	// 현재 체크하는 Object의 주소값을 BodyPtr로 받아서 BodyGroup을 순회
	// 이방법을 사용할 시 절대 내부에서 BodyGroup을 변경하면 안됨
	for (ConsoleGameObject* BodyPtr : BodyGroup)
	{
		if (nullptr == BodyPtr)
		{
			continue;
		}

		int2 BodyPos = BodyPtr->GetPos();
		// Player(this)의 GetPos()값이 순회중인 Body의 BodyPos와 값이 같으면
		if (GetPos() == BodyPos)
		{
			// ConsoleGameObject*를 dynamic_cast로 Parts*로 바꿔줌
			// (Parts의 내부 함수를 사용하기 위해)
			// (현재 순회중인 원소는 Body(Parts의 자식클래스)이기 때문에 Parts로 casting)
			Parts* BodyPart = dynamic_cast<Parts*>(BodyPtr);

			if (nullptr == BodyPtr)
			{
				// 위의 dynamic_cast 중 Parts*가 아닌 원소들은 Null로 리턴하기 때문 
				MsgBoxAssert("바디그룹 쪽에 바디가 아닌 객체가 들어가 있습니다.");
				return;
			}

			// 현재 Body들 중 마지막 Body를 리턴함
			Parts* Last = GetLast();

			// Head의 위치와 BodyPos의 위치가 같으면 (Head가 Body를 먹으면)
			// 현재 마지막Body의 Next를 방금 먹은 Body로 세팅
			Last->SetNext(BodyPart);
			ConsoleObjectManager::CreateConsoleObject<Body>(SnakeGameOrder::Body);
			return;
		}
	}
}

void Head::NewBodyCreateCheck()
{

}

void Head::Update()
{
	// 내부 데이터 확인용
	this;

	// 화면밖으로 나가면 사망판정
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}

	if (0 == _kbhit())
	{
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0 , 0 };

	// 누르는 방향키에 따라 이동방향 변경
	switch (Ch)
	{
	case'a':
	case'A':
		Dir = int2::Left;
		break;
	case 'd':
	case 'D':
		Dir = int2::Right;
		break;
	case 'w':
	case 'W':
		Dir = int2::Up;
		break;
	case 's':
	case 'S':
		Dir = int2::Down;
		break;
	case 'q':
	case 'Q':
		IsPlay = false;
		return;
	default:
		break;
	}

	SetPos(GetPos() + Dir);
	IsBodyCheck();
	// 바디들이 움직임
	NextMove();
	NewBodyCreateCheck();

	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}
}