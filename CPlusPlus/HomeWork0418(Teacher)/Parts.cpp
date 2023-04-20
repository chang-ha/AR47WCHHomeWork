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

// ������
// Body�� ������ �κ�(���� �����κ�)�� RenderChar�� �ѹ��� �ʰ� ����Ǵ� ���� �߻�
// ���� RenderChar�� �ٲ��ֱ� ���� ���� ������尡 �ʿ���
// ������ �κ�(���� �����κ�)�� ���� ��尡 ���� ������ �߻��ϴ� ���׷� �����
// �ذ���
// ���� ���� ����� RenderChar�� �����ָ� ��
// �׷��� ��尡 ���������� ������ ����
// Head�� ���� ������ RenderChar�� ������ �� �� �ֱ� ������ Head���ο��� RenderChar�� ����
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
		Next->RenderChar = L'��';
	}
	else if (Dir == int2::Down)
	{
		Next->RenderChar = L'��';
	}
	else if (Dir == int2::Left)
	{
		Next->RenderChar = L'��';
	}
	else if (Dir == int2::Right)
	{
		Next->RenderChar = L'��';
	}


	return Next->NextMove();
}