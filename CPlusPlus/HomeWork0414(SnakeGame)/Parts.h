#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

class Body;
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

	int2 GetBeforePos() const
	{
		return BeforePos;
	}

protected:
	void Update() override;
	void Death() override;
	Parts* Prev = nullptr;
	Parts* Next = nullptr;
	int2 BeforePos = { 0 , 0 };
private:
};

