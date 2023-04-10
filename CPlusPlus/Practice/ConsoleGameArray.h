#pragma once

#include <iostream>
#include "Base.h"
template<typename DataType>
class ConsoleGameArray
{
public:
	// delete function
	ConsoleGameArray(const ConsoleGameArray& _Ohter) = delete;
	ConsoleGameArray(ConsoleGameArray&& _Ohter) noexcept = delete;
	ConsoleGameArray& operator=(ConsoleGameArray&& _Other) noexcept = delete;

	// constructer destructer
	ConsoleGameArray(size_t _Value)
		: ArrPtr(new DataType[_Value])
		, ArrCount(_Value)
	{
		if (0 == _Value)
		{
			MsgBoxAssert("배열의 크기는 0일수 없습니다.");
		}
	}
	~ConsoleGameArray()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	DataType& operator[](size_t _Index) const
	{
		return ArrPtr[_Index];
	}

	size_t Count()
	{
		return ArrCount;
	}

	void ReSize(size_t _Value)
	{
		DataType* NewPtr = nullptr;
		NewPtr = new DataType[_Value];
		size_t CopyCount = _Value < ArrCount ? _Value : ArrCount;

		for (size_t i = 0; i < CopyCount; i++)
		{
			NewPtr[i] = ArrPtr[i]; 
		}

		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
		ArrPtr = NewPtr;
		ArrCount = _Value;
	}
	ConsoleGameArray& operator=(const ConsoleGameArray& _Other)
	{
		ReSize(_Other.ArrCount);
		for (size_t i = 0; i < _Other.ArrCount; i++)
		{
			ArrPtr[i] = _Other[i];
		}
		return *this;
	}

	template<typename DataType>
	void Print(DataType _Value)
	{
		printf_s("%d\n", _Value);
	}

	template<>
	void Print(char _Value)
	{
		printf_s("%c\n", _Value);
	}

	void AllPrint()
	{
		for (size_t i = 0; i < ArrCount; i++)
		{
			Print(ArrPtr[i]);
		}
	}
protected:

private:
	DataType* ArrPtr = nullptr;
	size_t ArrCount;
};