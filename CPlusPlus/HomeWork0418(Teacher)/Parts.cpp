#include "Parts.h"

Parts::Parts() 
{
}

Parts::~Parts() 
{
}

void Parts::Update() 
{

}

// 문제점
// Body의 마지막 부분(가장 꼬리부분)의 RenderChar이 한박자 늦게 변경되는 버그 발생
// 나의 RenderChar을 바꿔주기 위해 나와 다음노드가 필요함
// 마지막 부분(가장 꼬리부분)은 다음 노드가 없기 때문에 발생하는 버그로 예상됨
// 해결방법
// 내가 다음 노드의 RenderChar을 정해주면 됨
// 그러면 헤드가 마지막으로 변하지 않음
// Head는 본인 스스로 RenderChar을 변경해 줄 수 있기 때문에 Head내부에서 RenderChar을 변경
void Parts::NextMove()
{
	if (nullptr == Next)
	{
		return;
	}
	Parts* Next = GetNext();
	Next->SetPos(GetPrevPos());

	int2 Pos = GetPos();
	int2 NextPos = Next->GetPos();
	Dir = Pos - NextPos;
	if (Dir == int2::Up)
	{
		Next->RenderChar = L'▲';
	}
	else if (Dir == int2::Down)
	{
		Next->RenderChar = L'▼';
	}
	else if (Dir == int2::Left)
	{
		Next->RenderChar = L'◀';
	}
	else if (Dir == int2::Right)
	{
		Next->RenderChar = L'▶';
	}


	return Next->NextMove();
}