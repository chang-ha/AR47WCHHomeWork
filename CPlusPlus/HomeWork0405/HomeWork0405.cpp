// HomeWork0405


#include <iostream>
#include "GameEngineArray.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	GameEngineArray Array0(10);
	GameEngineArray Array1(5);

	for (size_t i = 0; i < Array0.Count(); i++)
	{
		Array0[i] = i;
	}

	printf_s("----------Array0----------\n");
	for (size_t i = 0; i < Array0.Count(); i++)
	{
		printf_s("%d\n", Array0[i]);
	}

	printf_s("----------LargeResize----------\n");

	Array0.Resize(15);
	for (size_t i = 0; i < Array0.Count(); i++)
	{
		printf_s("%d\n", Array0[i]);
	}

	printf_s("----------SmallResize----------\n");

	Array0.Resize(5);
	for (size_t i = 0; i < Array0.Count(); i++)
	{
		printf_s("%d\n", Array0[i]);
	}
	
	printf_s("----------Array1 = Array0----------\n");
	Array1 = Array0;
	for (size_t i = 0; i < Array1.Count(); i++)
	{
		printf_s("%d\n", Array1[i]);
	}
}

