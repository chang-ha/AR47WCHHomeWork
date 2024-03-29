#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleGameScreen.h>


class ConsoleGameScreen;
class Bomb : public ConsoleGameObject
{
public:
	// constructer destructer
	Bomb();
	~Bomb();

	// delete function
	Bomb(const Bomb& _Ohter) = delete;
	Bomb(Bomb&& _Ohter) noexcept = delete;
	Bomb& operator=(const Bomb& _Other) = delete;
	Bomb& operator=(Bomb&& _Other) noexcept = delete;

protected:
	void Update() override;
	void Render() override; 

private:
	int BombCount = 0;
	int Power = 3;
	int step = 1;
};

