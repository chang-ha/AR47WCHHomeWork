#include "Monster.h"
#include "ConsoleGameScreen.h"

int Monster::Dir = -1;

Monster::Monster() 
{
	RenderChar = 'M';
}

void Monster::Update() 
{
	if (false == IsUpdate())
	{
		return;
	}
}