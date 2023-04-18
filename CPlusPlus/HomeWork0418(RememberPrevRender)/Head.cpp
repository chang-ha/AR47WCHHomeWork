#include "Head.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include <list>
#include "ConsoleObjectManager.h"
#include "GameEnum.h"
#include "Body.h"

bool Head::IsPlay = true;

Head::Head() 
{
	RenderChar = L'��';
	PrevRender = L'��';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head() 
{
}

void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*>& BombGroup
		= ConsoleObjectManager::GetGroup(SnakeGameOrder::Body);

	for (ConsoleGameObject* BodyPtr : BombGroup)
	{
		// �������� �ֽ��ϴ�.
		if (nullptr == BodyPtr)
		{
			continue;
		}

		int2 BodyPos = BodyPtr->GetPos();
		if (GetPos() == BodyPos)
		{
			Parts* BodyPart = dynamic_cast<Parts*>(BodyPtr);

			if (nullptr == BodyPart)
			{
				MsgBoxAssert("�ٵ�׷� �ʿ� �ٵ� �ƴ� ��ü�� ����־����ϴ�.");
				return;
			}

			Parts* Last = GetLast();
			Last->SetNext(BodyPart);
			BodyPart->SetRenderChar(Last->GetPrevRender());
			ConsoleObjectManager::CreateConsoleObject<Body>(SnakeGameOrder::Body);
			return;
		}
	}
}

// ȭ��ٱ����� �������� �ϼ���. 
void Head::Update()
{
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}

	if (0 == _kbhit())
	{
		// SetPos(GetPos() + Dir);
		// IsBodyCheck();
		// NewBodyCreateCheck();
		return;
	}

	char Ch = _getch();
	switch (Ch)
	{
	case 'a':
	case 'A':
		Dir = int2::Left;
		PrevRender = RenderChar;
		RenderChar = L'��';
		break;
	case 'd':
	case 'D':
		Dir = int2::Right;
		PrevRender = RenderChar;
		RenderChar = L'��';
		break;	
	case 'w':
	case 'W':
		Dir = int2::Up;
		PrevRender = RenderChar;
		RenderChar = L'��';
		break;
	case 's':
	case 'S':
		Dir = int2::Down;
		PrevRender = RenderChar;
		RenderChar = L'��';
		break;
	case 'q':
	case 'Q':
		IsPlay = false;
		return;
	default:
		return;
	}

	SetPos(GetPos() + Dir);
	IsBodyCheck();
	NextMove();

	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}



}
