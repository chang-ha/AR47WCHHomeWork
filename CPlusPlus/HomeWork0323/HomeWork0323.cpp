#include <iostream>

class Number
{
private:
	int Value;
	int* ValuePtr;
	int Arr[10];

public:
	Number(int _Value)
		: Value(_Value)
		, ValuePtr(nullptr)
		, Arr{}
	{
	}

	// + 연산자
	int operator+(int _Value)
	{
		return Value + _Value;
	}
	int operator++(int _Value)
	{
		return Value + 1;
	}
	int operator+=(int _Value)
	{
		return Value = Value + _Value;
	}

	// - 연산자
	int operator-(int _Value)
	{
		return Value - _Value;
	}
	int operator--(int _Value)
	{
		return Value - 1;
	}
	int operator-=(int _Value)
	{
		return Value = Value - _Value;
	}

	// * 연산자
	int operator*(int _Value)
	{
		return Value * _Value;
	}
	int operator*=(int _Value)
	{
		return Value = Value * _Value;
	}

	// / 연산자
	int operator/(int _Value)
	{
		return Value / _Value;
	}
	int operator/=(int _Value)
	{
		return Value = Value / _Value;
	}

	// %연산자
	int operator%(int _Value)
	{
		return Value % _Value;
	}
	int operator%=(int _Value)
	{
		return Value = Value % _Value;
	}

	// 비트연산자
	int operator&(int _Value)
	{
		return Value & _Value;
	}
	int operator&=(int _Value)
	{
		return Value = Value & _Value;
	}
	int operator|(int _Value)
	{
		return Value | _Value;
	}
	int operator|=(int _Value)
	{
		return Value = Value | _Value;
	}
	int operator~()
	{
		return ~Value;
	}
	int operator^(int _Value)
	{
		return Value ^ _Value;
	}
	int operator<<(int _Value)
	{
		return Value << _Value;
	}
	int operator<<=(int _Value)
	{
		return Value = Value << _Value;
	}
	int operator>>(int _Value)
	{
		return Value >> _Value;
	}
	int operator>>=(int _Value)
	{
		return Value = Value >> _Value;
	}

	// 논리연산자
	bool operator==(bool _Value)
	{
		return Value == _Value;
	}
	bool operator!=(bool _Value)
	{
		return Value != _Value;
	}
	bool operator!()
	{
		return (bool)!Value;
	}
	bool operator&&(int _Value)
	{
		return Value&&_Value;
	}
	bool operator||(int _Value)
	{
		return Value || _Value;
	}

	// 비교연산자
	bool operator>(int _Value)
	{
		return Value > _Value;
	}
	bool operator>=(int _Value)
	{
		return Value >= _Value;
	}

	// 포인터연산자
	int* operator*(int* _ValuePtr)
	{
		return _ValuePtr;
	}
	__int64 operator&(int* _Value)
	{
		return (__int64) & _Value;
	}
	int* operator->()
	{
		return ValuePtr;
	}

	// 배열연산자
	int operator[](int _Value)
	{
		return Arr[_Value];
	}

	// 함수호출연산자
	void operator()()
	{
		printf_s("함수호출");
	}

	// 형변환연산자
	bool operator()(int _Value)
	{
		return (bool)_Value;
	}


	// 불가능한 연산자
 
	//// 삼항연산자
	//int operator?()
	//{
	//	return ;
	//}
	//// 전처리기 연산자
	//void operator#()
	//{
	//	#include<iostream>
	//}
	//// 멤버호출 연산자
	//int operator.() 
	//{
	//	return ;
	//}
	//// 범위확인 연산자
	//void operator::()
	//{
	//	return ;
	//}
};
int main()
{
	Number NewNumber = 0;
	int Result = 0;
	int* ResultPtr = &Result;
	bool TrueFalse = false;

	// + 연산자
	Result = NewNumber + 10;
	Result = NewNumber++;
	NewNumber += 10;

	// - 연산자
	Result = NewNumber - 10;
	Result = NewNumber--;
	NewNumber -= 10;

	// * 연산자
	Result = NewNumber * 10;
	NewNumber *= 10;

	// / 연산자
	Result = NewNumber / 10;
	NewNumber /= 10;

	// % 연산자
	Result = NewNumber % 10;
	NewNumber %= 10;

	// 비트연산자
	Result = NewNumber & 10;
	NewNumber &= 10;
	Result = NewNumber | 10;
	NewNumber |= 10;
	Result = ~NewNumber;
	Result = NewNumber ^ 10;
	Result = NewNumber >> 1;
	Result = NewNumber << 1;
	NewNumber >>= 1;
	NewNumber <<= 1;

	// 논리연산자
	Result = NewNumber == 10;
	Result = NewNumber != 10;
	TrueFalse = !NewNumber;
	TrueFalse = NewNumber && 10;
	TrueFalse = NewNumber || 10;
	TrueFalse = NewNumber > 100;
	TrueFalse = NewNumber >= 0;

	// 포인터연산자
	int* TestPtr = NewNumber*ResultPtr;
	__int64 Address = NewNumber & ResultPtr;
	
	// 배열연산자
	Result = NewNumber[2];

	// 함수호출 연산자
	NewNumber();

	// 형변환연산자
	TrueFalse = NewNumber(0);

	// 치트키
	 int a = 0;
}

