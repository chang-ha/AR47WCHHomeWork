#pragma once
#include "ConsoleGameMath.h"

// Screen에서 움직이는 오브젝트들의 기본기능을 제공한다.
class ConsoleGameObject
{
public:
	virtual inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	bool IsDeath()
	{
		return DeathValue;
	}

	void Death()
	{
		DeathValue = true;
	}

	bool IsUpdate()
	{
		return UpdateValue && false == IsDeath();
	}

	void On()
	{
		UpdateValue = true;
	}

	void Off()
	{
		UpdateValue = false;
	}

	virtual void Update();
	virtual void Render();

	void SetRenderChar(wchar_t _Ch)
	{
		RenderChar = _Ch;
	}

	wchar_t GetRenderChar()
	{
		return RenderChar;
	}

	void SetPrevRender(wchar_t _Ch)
	{
		PrevRender = _Ch;
	}

	wchar_t GetPrevRender()
	{
		return PrevRender;
	}
protected:
	int2 Pos;
	wchar_t RenderChar = L'＠';
	wchar_t PrevRender = L' ';


private:
	bool UpdateValue = true;
	bool DeathValue = false;

};

