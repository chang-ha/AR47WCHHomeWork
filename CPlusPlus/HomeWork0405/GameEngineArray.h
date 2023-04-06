#pragma once


typedef int DataType;

class GameEngineArray
{
public:

	// delete function
	GameEngineArray(const GameEngineArray& _Ohter) = delete;
	GameEngineArray(GameEngineArray&& _Ohter) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;

	// constructer destructer
	GameEngineArray(DataType _Value)
		: ArrCount(_Value)
		, ArrPtr(new DataType[_Value])
	{

	}

	~GameEngineArray()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	size_t Count()
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	void Resize(size_t _Value)
	{
		// ���� 1, 2.
		DataType* OldPtr = nullptr;

		OldPtr = ArrPtr;
		ArrPtr = new DataType[_Value];

		for (size_t i = 0; i < _Value; i++)
		{
			if (i >= ArrCount)
			{
				continue;
			}
			ArrPtr[i] = OldPtr[i];
		}
		ArrCount = _Value;

		if (nullptr != OldPtr)
		{
			delete[] OldPtr;
			OldPtr = nullptr;
		}
	}

	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		// ���� ����
		// ArrCount = _Other.ArrCount;
		// ArrPtr = _Other.ArrPtr;

		// ���� 3. �����߻� ����
		// Array0�� ArrPtr�� 100����, Array1�� ArrPtr�� 200������� �����ϸ�
		// �����ϱ��� operator=�� ����ϸ�
		// Array0�� ArrPtr�� 100����, Array1�� ArrPtr�� 100������ ������ �ּҸ� ����Ű�� ����
		// �� �Ŀ� main�Լ��� ������ ~GameEngineArray() (�Ҹ����Լ�)�� ȣ��� ��
		// ���� Array1�� �Ҹ��ڰ� ȣ��Ǹ鼭 Array1�� ArrPtr�� ����Ű�� �ִ�  100������ �����ϰ�
		// �� ������ Array0�� �Ҹ��ڰ� ȣ��Ǹ鼭 Array0�� ArrPtr�� ����Ű�� �ִ� 100������ �����Ϸ��� �� ��
		// �̹� 100������ delete[]�� �Ǿ��ֱ� ������ "�޸� ũ����"�� �߻��Ѵ�.
		
		
		// ���� 3, 4.
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		ArrPtr = new DataType[_Other.ArrCount];
		for (size_t i = 0; i < _Other.ArrCount; i++)
		{
			ArrPtr[i] = _Other.ArrPtr[i];
		}
		ArrCount = _Other.ArrCount;
		return *this;
	}
protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;
};

