#pragma once
#include "Parts.h"

class Head : public Parts
{
public:
	// constructer destructer
	Head();
	~Head();

	// delete function
	Head(const Head& _Ohter) = delete;
	Head(Head&& _Ohter) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

	// ���� �÷��� ������ üũ�ϴ� bool��
	static bool IsPlay;

protected:
	void Update() override;

	//
	void IsBodyCheck();

	//
	void NewBodyCreateCheck();

private:
	// ���� Head�� �������� ���� �������� �̵�
	int2 Dir = int2::Up;

};

