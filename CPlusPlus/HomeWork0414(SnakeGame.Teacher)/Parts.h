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
			// ������ Body�� ������ ����
			return this;
		}
		// �ƴϸ� ���� ����Body�ΰ��� GetLast()�Լ��� ȣ��
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
			MsgBoxAssert("�ڽ��� NextNode�� nullptr�� �����Ϸ��� �߽��ϴ�.")
		}
		Next = _Next;
	}

	inline int2 GetPrevPos()
	{
		return PrevPos;
	}

	inline void SetPos(const int2& _Value) override
	{
		// Parts�� SetPos�� �����Ҷ���
		// PrevPos �� ���� ��ġ�� ������ ����
		// SetPos(_Value)�� ���� ��ġ�� �̵�
		PrevPos = GetPos();
		ConsoleGameObject::SetPos(_Value);
	}

	void NextMove();
protected:
	void Update() override;
private:
	// ���� ��ġ�� ���
	int2 PrevPos;

	// ���� ������ ���� Parts�� ����ϱ� ���� Linked List�������� �ۼ�
	Parts* Prev;
	Parts* Next;
};

