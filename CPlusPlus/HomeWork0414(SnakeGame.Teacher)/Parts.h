#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineBase/GameEngineDebug.h>

class Parts : public ConsoleGameObject
{
public:
	// constructer destructer
	Parts();
	~Parts();

	// delete function
	Parts(const Parts& _Ohter) = delete;
	Parts(Parts&& _Ohter) noexcept = delete;
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

	inline Parts* GetLast()
	{
		if (nullptr == Next)
		{
			// 마지막 Body면 본인을 리턴
			return this;
		}
		// 아니면 나의 다음Body로가서 GetLast()함수를 호출
		return Next->GetLast();
	}

	inline Parts* GetNext()
	{
		return Next;
	}

	inline void SetNext(Parts* _Next)
	{
		if (nullptr == _Next)
		{
			MsgBoxAssert("자신의 NextNode를 nullptr로 세팅하려고 했습니다.")
		}
		Next = _Next;
	}

	inline int2 GetPrevPos()
	{
		return PrevPos;
	}

	inline void SetPos(const int2& _Value) override
	{
		// Parts가 SetPos를 동작할때는
		// PrevPos 에 현재 위치를 저장한 다음
		// SetPos(_Value)로 다음 위치로 이동
		PrevPos = GetPos();
		ConsoleGameObject::SetPos(_Value);
	}

	void NextMove();
protected:
	void Update() override;
private:
	// 이전 위치를 기억
	int2 PrevPos;

	// 나의 이전과 다음 Parts를 기억하기 위해 Linked List형식으로 작성
	Parts* Prev;
	Parts* Next;
};

