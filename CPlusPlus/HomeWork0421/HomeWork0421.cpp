// HomeWork0421


#include <iostream>
#include <map>
#include <list>
#include "GameEngineMap.h"

int main()
{
    GameEngineDebug::LeckCheck();

    {
        GameEngineMap<int, int> Test;
        Test.insert(GameEnginePair<int, int>(10, rand()));
        Test.insert(GameEnginePair<int, int>(7, rand()));
        Test.insert(GameEnginePair<int, int>(15, rand()));
        Test.insert(GameEnginePair<int, int>(25, rand()));
        Test.insert(GameEnginePair<int, int>(17, rand()));
        Test.insert(GameEnginePair<int, int>(18, rand()));
        Test.insert(GameEnginePair<int, int>(2, rand()));
        Test.insert(GameEnginePair<int, int>(6, rand()));
        Test.insert(GameEnginePair<int, int>(5, rand()));
        Test.insert(GameEnginePair<int, int>(4, rand()));
        Test.insert(GameEnginePair<int, int>(9, rand()));
        Test.insert(GameEnginePair<int, int>(8, rand()));
        Test.insert(GameEnginePair<int, int>(1, rand()));

        std::cout << "그냥 돌리기" << std::endl;
        GameEngineMap<int, int>::iterator StartIter = Test.begin();
        GameEngineMap<int, int>::iterator EndIter = Test.end();
        for (; StartIter != EndIter; ++StartIter)
        {
            std::cout << StartIter->first << std::endl;
        }

        std::cout << "전위 순회" << std::endl;
        Test.FirstOrder();
        std::cout << "중위 순회" << std::endl;
        Test.MidOrder();
        std::cout << "후위 순회" << std::endl;
        Test.LastOrder();
    }

}