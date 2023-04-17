#include "Parts.h"


Parts::Parts()
{

}

Parts::~Parts()
{

}

void Parts::Update()
{
	ConsoleGameObject::Update();
}

void Parts::NextMove()
{
	Parts* Next = GetNext();

	if (nullptr == Next)
	{
		return;
	}

	Next->SetPos(GetPrevPos());
	return Next->NextMove();
}