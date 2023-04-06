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
		// 숙제 1, 2.
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
		// 얕은 복사
		// ArrCount = _Other.ArrCount;
		// ArrPtr = _Other.ArrPtr;

		// 숙제 3. 에러발생 원인
		// Array0의 ArrPtr은 100번지, Array1의 ArrPtr은 200번지라고 가정하면
		// 수정하기전 operator=를 사용하면
		// Array0의 ArrPtr은 100번지, Array1의 ArrPtr은 100번지로 동일한 주소를 가리키고 있음
		// 그 후에 main함수가 끝나고 ~GameEngineArray() (소멸자함수)가 호출될 때
		// 먼저 Array1의 소멸자가 호출되면서 Array1의 ArrPtr이 가리키고 있는  100번지를 삭제하고
		// 그 다음에 Array0의 소멸자가 호출되면서 Array0의 ArrPtr이 가리키고 있는 100번지를 삭제하려고 할 떄
		// 이미 100번지는 delete[]가 되어있기 때문에 "메모리 크러쉬"가 발생한다.
		
		
		// 숙제 3, 4.
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

