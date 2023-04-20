// HomeWork0420


#include <iostream>
#include <map>
#include "HomeWork0420.h"
#include <list>
int main()
{
	{
		GameEngineMap Test;
		Test.insert(GameEnginepair(10, rand()));
		Test.insert(GameEnginepair(7, rand()));
		Test.insert(GameEnginepair(15, rand()));
		Test.insert(GameEnginepair(25, rand()));
		Test.insert(GameEnginepair(17, rand()));
		Test.insert(GameEnginepair(18, rand()));
		Test.insert(GameEnginepair(2, rand()));
		Test.insert(GameEnginepair(6, rand()));
		Test.insert(GameEnginepair(5, rand()));
		Test.insert(GameEnginepair(4, rand()));
		Test.insert(GameEnginepair(9, rand()));
		Test.insert(GameEnginepair(8, rand()));
		Test.insert(GameEnginepair(1, rand()));

		GameEngineMap::iterator Find = Test.find(25);
		GameEngineMap::iterator Start = Test.begin();
		GameEngineMap::iterator End = Test.end();

		GameEngineMap::iterator rStart = Test.rbegin();
		GameEngineMap::iterator rEnd = Test.rend();

		for (; rStart != rEnd; --rStart)
		{
			std::cout << rStart->first << std::endl;
		}

		//for (; Start != End; ++Start)
		//{
		//	std::cout << Start->first << std::endl;
		//}
		int a = 0;
	}
}