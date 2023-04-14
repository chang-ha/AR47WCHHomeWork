#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

// 첫번째 숙제
// 먹으면 플레이어의 폭탄 위력이 증가하도록 바꾸세요
// 1. 먹으면 사라져야함
// 2. 사라지면 Death
// 3. 플레이어의 폭탄 위력을 알아야할까??
// 4. 그 위력을 +1 해서 돌려줌

class ConsoleGameScreen;
class Item : public ConsoleGameObject
{
public:
	// constructer destructer
	Item();
	~Item();

	// delete function
	Item(const Item& _Ohter) = delete;
	Item(Item&& _Ohter) noexcept = delete;
	Item& operator=(const Item& _Other) = delete;
	Item& operator=(Item&& _Other) noexcept = delete;

	void Update() override;
protected:

private:
};

