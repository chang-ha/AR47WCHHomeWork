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

	// 현재 플레이 중인지 체크하는 bool값
	static bool IsPlay;

protected:
	void Update() override;

	//
	void IsBodyCheck();

	//
	void NewBodyCreateCheck();

private:
	// 최초 Head의 움직임은 위쪽 방향으로 이동
	int2 Dir = int2::Up;

};

