// HomeWokr0323.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class Number
{
private:
	int Value;

public:
	// 맴버 이니셜라이저.
	Number(int _Value)
		: Value(_Value)
	{

	}

#pragma region 산술 연산자

	// +, 덧셈 연산자
	const int operator+(const int& _a)
	{
		printf("덧셈 연산자(+)가 호출되었습니다.\n");
		return Value + _a;
	}

	// -, 뺄셈 연산자
	int operator-(const int& _a)
	{
		int nResult = 0;
		printf("뺄셈 연산자(-)가 호출되었습니다.\n");
		return nResult;
	}

	// *, 곱셈 연산자
	int operator*(const int& _a)
	{
		int nResult = 0;
		printf("곱셈 연산자(*)가 호출되었습니다.\n");
		return nResult;
	}

	// /, 나누기 연산자
	int operator/(const int& _a)
	{
		int nResult = 0;
		printf("나누기 연산자(/)가 호출되었습니다.\n");
		return nResult;
	}

	// %, 나머지 연산자
	int operator%(const int& _a)
	{
		int nResult = 0;
		printf("나머지 연산자(%%)가 호출되었습니다.\n");
		return nResult;
	}

	// =, 대입 연산자
	int operator=(const int& _a)
	{
		int nResult = 0;
		printf("대입 연산자(=)가 호출되었습니다.\n");
		return nResult;
	}

	// +a, 단항 덧셈 연산자
	int operator+()
	{
		int nResult = 0;
		printf("단항 덧셈 연산자(+)가 호출되었습니다.\n");
		return nResult;
	}

	// -a, 단항 뺄셈 연산자
	int operator-()
	{
		int nResult = 0;
		printf("단항 뺄셈 연산자(-)가 호출되었습니다.\n");
		return nResult;
	}

	// ++a, 전위 증가 연산자
	// Number& operator++()
	void operator++()
	{
		++Value;
		// return *this;
		return;
	}

	// a++, 후위 증가 연산자
	// 후위의 경우 인자를 넣어주지만 사용할수는 없다.
	int operator++(int)
	{
		int nResult = Value;
		Value += 1;
		return nResult;
	}

	// --a, 전위 감소 연산자
	int operator--()
	{
		int nResult = 0;
		printf("전위 증가 연산자(--a)가 호출되었습니다.\n");
		return nResult;
	}

	// a--, 후위 증가 연산자
	int operator--(int _a)
	{
		int nResult = 0;
		printf("후위 증가 연산자(a--)가 호출되었습니다.\n");
		return nResult;
	}

#pragma endregion

#pragma region 비교 연산자 & 관계 연산자

	// ==, 비교 연산자
	bool operator==(const int& _a)
	{
		int nResult = 0;
		printf("비교 연산자(==)가 호출되었습니다.\n");
		return nResult;
	}

	// !=, 비교 연산자
	bool operator!=(const int& _a)
	{
		int nResult = 0;
		printf("비교 연산자(!=)가 호출되었습니다.\n");
		return nResult;
	}

	// >, 크기 비교 연산자
	bool operator>(const int& _a)
	{
		int nResult = 0;
		printf("크기 비교 연산자(>)가 호출되었습니다.\n");
		return nResult;
	}

	// <, 크기 비교 연산자
	bool operator<(const int& _a)
	{
		int nResult = 0;
		printf("크기 비교 연산자(<)가 호출되었습니다.\n");
		return nResult;
	}

	// <=, 크기 비교 연산자
	bool operator<=(const int& _a)
	{
		int nResult = 0;
		printf("크기 비교 연산자(<=)가 호출되었습니다.\n");
		return nResult;
	}

	// >=, 크기 비교 연산자
	bool operator>=(const int& _a)
	{
		int nResult = 0;
		printf("크기 비교 연산자(>=)가 호출되었습니다.\n");
		return nResult;
	}

#pragma endregion

#pragma region 논리 연산자

	// &&, 논리 AND 연산자
	bool operator&&(const int& _a)
	{
		int nResult = 0;
		printf("논리 AND 연산자(&&)가 호출되었습니다.\n");
		return nResult;
	}

	// ||, 논리 OR 연산자
	bool operator||(const int& _a)
	{
		int nResult = 0;
		printf("논리 OR 연산자(||)가 호출되었습니다.\n");
		return nResult;
	}

	// !a, 논리 부정 연산자
	bool operator!()
	{
		int nResult = 0;
		printf("논리 부정 연산자(!a)가 호출되었습니다.\n");
		return nResult;
	}


#pragma endregion

#pragma region 비트연산자

	// ~, 비트 NOT 연산자
	int operator~()
	{
		int nResult = 0;
		printf("비트 NOT 연산자(~)가 호출되었습니다.\n");
		return nResult;
	}

	// &, 비트 AND 연산자
	int operator&(const int& _a)
	{
		int nResult = 0;
		printf("비트 AND 연산자(&)가 호출되었습니다.\n");
		return nResult;
	}

	// |, 비트 OR 연산자
	int operator|(const int& _a)
	{
		int nResult = 0;
		printf("비트 OR 연산자(|)가 호출되었습니다.\n");
		return nResult;
	}

	// ^, 비트 XOR 연산자
	int operator^(const int& _a)
	{
		int nResult = 0;
		printf("비트 XOR 연산자(^)가 호출되었습니다.\n");
		return nResult;
	}

	// >>, 비트 오른쪽 시프트 연산자
	int operator>>(const int& _a)
	{
		int nResult = 0;
		printf("비트 오른쪽 시프트 연산자(>>)가 호출되었습니다.\n");
		return nResult;
	}

	// <<, 비트 왼쪽 시프트 연산자
	int operator<<(const int& _a)
	{
		int nResult = 0;
		printf("비트 왼쪽 시프트 연산자(<<)가 호출되었습니다.\n");
		return nResult;
	}


#pragma endregion

#pragma region 복합 할당 연산자

	// +=, 덧셈 대입 연산자
	Number& operator+=(const int& _a)
	{
		Value += _a;
		printf("덧셈 대입 연산자(+=)가 호출되었습니다.\n");

		// Number* const Ptr;
		// *Ptr
		return *this;
	}

	// -=, 뺄셈 대입 연산자
	int operator-=(const int& _a)
	{
		int nResult = 0;
		printf("뺄셈 대입 연산자(-=)가 호출되었습니다.\n");
		return nResult;
	}

	// *=, 곱셈 대입 연산자
	int operator*=(const int& _a)
	{
		int nResult = 0;
		printf("곱셈 대입 연산자(*=)가 호출되었습니다.\n");
		return nResult;
	}

	// /=, 나눗셈 대입 연산자
	int operator/=(const int& _a)
	{
		int nResult = 0;
		printf("나눗셈 대입 연산자(/=)가 호출되었습니다.\n");
		return nResult;
	}

	// %=, 나머지 대입 연산자
	int operator%=(const int& _a)
	{
		int nResult = 0;
		printf("나머지 대입 연산자(%%=)가 호출되었습니다.\n");
		return nResult;
	}

#pragma endregion

#pragma region 멤버 & 포인터 연산자

	// a[b], 배열 연산자
	int operator[](const int& _a)
	{
		int nResult = 0;
		printf("배열 연산자([])가 호출되었습니다.\n");
		return nResult;
	}

	//// *a, 포인터 연산자
	//int& Number::operator*(const int& _a)
	//{
	//	printf("포인터 연산자(*)가 호출되었습니다.\n");
	//	return nResult;
	//}

	// &a, 참조 연산자
	Number* operator&()
	{
		int nResult = 0;
		printf("참조 연산자(&a)가 호출되었습니다.\n");
		return this;
	}

	// a->b, 포인터 객체 할당 멤버 연산자
	int* operator->()
	{
		int nResult = 0;
		printf("포인터 객체 할당 멤버 연산자(->)가 호출되었습니다.\n");
		return &nResult;
	}

	//// a.b, 객체 멤버 지정 연산자 => 다중 정의 불가
	//int operator.()
	//{
	//	printf("객체 멤버 지정 연산자(.)가 호출되었습니다.\n");
	//	return &nResult;
	//}



#pragma endregion

#pragma region 그 외 연산자

	//// sizeof(a), sizeof() 연산자 => 다중 정의 불가
	//int operatorsizeof()()
	//{
	//	printf("sizeof() 연산자가 호출되었습니다.\n");
	//	return nResult;
	//}

	//// a?b:c, 삼항 연산자 => 다중 정의 불가
	//int operatora?b:c(const int& _a)
	//{
	//	printf("삼항 연산자가 호출되었습니다.\n");
	//	return nResult;
	//}

	// (,), 구분 연산자
	int operator,(const int& _a)
	{
		int nResult = 0;
		printf("구분 연산자(,)가 호출되었습니다.\n");
		return nResult;
	}



#pragma endregion

};

int Test()
{
	return 10;
}

class Boss
{

};

class Monster
{
public:
	Boss  operator+(const Monster& _Monster)
	{

	}
};

int main()
{
	Monster NewMonster0;
	Monster NewMonster1;

	NewMonster0 + NewMonster1;

	// 문법적으로 정해졌다.
	// unamed memory에는 우리가 간섭하여 수정할수는 없고
	// 그걸 받아서 사용만 가능하다.
	// 보이지 않는 4바이트 = 10; <= c++문법적으로 허용되지 않았다.

	int RealNumber = 10;
	(RealNumber + 10);
	(RealNumber += 10) = 10;
	RealNumber = 0;
	++RealNumber = 20;
	RealNumber++ = 20;

	Number NewNumber = 10;
	// 보이지 않는 4바이트 메모리가 생겨야 한다.
	// unnamed value는 우리가 거기에다가 값을 다시 집어넣을수 없다.
	NewNumber.operator+(10)/* = 10*/;
	(NewNumber += 10) = 10;
	// ++NewNumber = 10;

	NewNumber.operator++() = 10;

	NewNumber = 10;
	Number* NewNumberPtr = &NewNumber;
	// 자기자신을 리턴하지 않고 새로운 메모리를 만들어서 리턴하므로
	// 그 메모리에 접근할수 없기 때문에 = 20이 불가능해진다.
	NewNumber++ = 20;
}
