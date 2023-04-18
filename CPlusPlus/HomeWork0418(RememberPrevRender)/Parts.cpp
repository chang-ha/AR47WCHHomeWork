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
	Next->PrevRender = Next->RenderChar;
	Next->RenderChar = PrevRender;
	Next->SetPos(GetPrevPos());
	return Next->NextMove();
}