#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include "Parts.h"

class ConsoleGameScreen;
class Body : public Parts
{
public:
	// constructer destructer
	Body();
	~Body();

	// delete function
	Body(const Body& _Ohter) = delete;
	Body(Body&& _Ohter) noexcept = delete;
	Body& operator=(const Body& _Other) = delete;
	Body& operator=(Body&& _Other) noexcept = delete;

	void Update() override;
	void CreateBody();
	void Death() override;
	bool IsPlayerEat() override;

protected:

private:
	bool PlayerEat = false;
};

