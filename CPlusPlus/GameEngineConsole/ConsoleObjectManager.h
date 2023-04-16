#pragma once
#include "GameEngineArray.h"
#include "ConsoleGameObject.h"
#include <vector>
#include <list>

class ConsoleObjectManager
{
private:
	static std::vector<std::list<ConsoleGameObject*>> AllObject;
public:
	template<typename ObjectType>
	static ObjectType* CreateConsoleObject(int _Order)
	{
		if (_Order >= AllObject.size())
		{
			AllObject.resize(_Order + 1);
		}
		std::list<ConsoleGameObject*>& Group = AllObject[_Order];

		ObjectType* NewObject = new ObjectType();

		Group.push_back(NewObject);

		return NewObject;
	}

	// 인자를 매번 (int)하기 귀찮으니 
	// 인자를 2종류 받을 수 있게 만듦
	template<typename ObjectType, typename EnumType>
	static ObjectType* CreateConsoleObject(EnumType _Order)
	{
		return CreateConsoleObject<ObjectType>((int)_Order);
	}

	static void ConsoleAllObjectUpdate();
	static void ConsoleAllObjectRender();
	// object를 delete할 때는 만든놈이 지우는 게 제일 좋음
	static void ConsoleAllObjectRelease();
	static void ConsoleAllObjectDelete();
	template<typename EnumType>
	static std::list<ConsoleGameObject*>& GetGroup(EnumType _Order)
	{
		return AllObject[(int)_Order];
	}

	static std::list<ConsoleGameObject*>& GetGroup(int _Order)
	{
		return AllObject[_Order];
	}


private:
	// constructer destructer
	ConsoleObjectManager();
	~ConsoleObjectManager();

	// delete function
	ConsoleObjectManager(const ConsoleObjectManager& _Ohter) = delete;
	ConsoleObjectManager(ConsoleObjectManager&& _Ohter) noexcept = delete;
	ConsoleObjectManager& operator=(const ConsoleObjectManager& _Other) = delete;
	ConsoleObjectManager& operator=(ConsoleObjectManager&& _Other) noexcept = delete;

protected:

};

