#include "Parts.h"

Parts::Parts() 
{
}

Parts::~Parts() 
{
}

void Parts::Update() 
{
	Dir = GetPos() - PrevPos;
	if (Dir == int2::Up)
	{
		RenderChar = L'��';
	}
	else if (Dir == int2::Down)
	{
		RenderChar = L'��';
	}
	else if (Dir == int2::Left)
	{
		RenderChar = L'��';
	}
	else if (Dir == int2::Right)
	{
		RenderChar = L'��';
	}
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