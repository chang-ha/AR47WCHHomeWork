#include <iostream>
#include <conio.h>
#include <Windows.h>

// w, a, s, d로 *을 움직여라
// 숙제 0. 상하좌우로 다 움직이게 만들기
// 숙제 1. 잔상지우기
// 숙제 2. 밖으로 못나가게 하기
// 숙제 3. 장애물 만들고 배치하기
// 숙제 4. f를 누르면 폭탄이 설치되게 만들기
// 숙제 5. 일정시간이 지나고 폭탄이 터져야함 (한번에 나오면 안됨, 순차적으로)

// 숙제 0. ~ 4. 까지 구현
int main()
{
	// 변수선언
	const int ScreenXSize = 16;
	const int ScreenYSize = 7;
	const char EmptySpace = 'a'; // 빈공간
	const char Block = 'X';		 // 장애물
	const char Bomb = 'B';		 // 폭탄

	// 맵초기화
	char Arr[ScreenYSize][ScreenXSize] = { 0, };
	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = EmptySpace;
		}
	}

	// 플레이어 시작위치
	int PlayerX = ScreenXSize / 2;
	int PlayerY = ScreenYSize / 2;
	Arr[PlayerY][PlayerX] = '*';

	// 장애물 3개 삽입
	const int Block_Number = 3;
	for (size_t i = 0; i < Block_Number; i++)
	{
		srand(time(0));
		int Xindex = rand() % ScreenXSize;
		int Yindex = rand() % ScreenYSize;
		if (Arr[Yindex][Xindex] == EmptySpace)
		{
			Arr[Yindex][Xindex] = Block;
		}
		else
		{
			i--;
		}
	}

	while (true)
	{
		system("cls");
		if (Arr[PlayerY][PlayerX] != Bomb)
		{
			Arr[PlayerY][PlayerX] = '*';
		}
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}
		if (0 == _kbhit())
		{
			Sleep(200);
			continue;
		}
		char Ch = _getch();
		switch (Ch)
		{
		case 'w':
			// 이동하려는 곳이 벽(맵 끝)이면 이동불가능
			if (PlayerY == 0) 
			{
				break;
			}
			// 이동하려는 곳이 장애물 or 폭탄인 경우 이동 불가능
			else if (Arr[PlayerY - 1][PlayerX] == Block || Arr[PlayerY - 1][PlayerX] == Bomb) 
			{
				break;
			}
			// 폭탄설치 후 이동, 이전 위치는 폭탄이므로 EmptySpace('a')로 변경하지 않음
			else if (Arr[PlayerY][PlayerX] == Bomb) 
			{
				PlayerY -= 1;
				break;
			}
			// 플레이어 이전 위치를 EmptySpace('a')로 변경 후 한 칸 이동 << 잔상제거
			Arr[PlayerY][PlayerX] = EmptySpace;
			PlayerY -= 1;						
			break;
		case 'a':
			if (PlayerX == 0)
			{
				break;
			}
			else if (Arr[PlayerY][PlayerX - 1] == Block || Arr[PlayerY][PlayerX - 1] == Bomb)
			{
				break;
			}
			else if (Arr[PlayerY][PlayerX] == Bomb)
			{
				PlayerX -= 1;
				break;
			}
			Arr[PlayerY][PlayerX] = EmptySpace;
			PlayerX -= 1;
			break;
		case 's':
			if (PlayerY == ScreenYSize - 1)
			{
				break;
			}
			else if (Arr[PlayerY + 1][PlayerX] == Block || Arr[PlayerY + 1][PlayerX] == Bomb)
			{
				break;
			}
			else if (Arr[PlayerY][PlayerX] == Bomb)
			{
				PlayerY += 1;
				break;
			}
			Arr[PlayerY][PlayerX] = EmptySpace;
			PlayerY += 1;
			break;
		case 'd':
			if (PlayerX == ScreenXSize - 1)
			{
				break;
			}
			else if (Arr[PlayerY][PlayerX + 1] == Block || Arr[PlayerY][PlayerX + 1] == Bomb)
			{
				break;
			}
			else if (Arr[PlayerY][PlayerX] == Bomb)
			{
				PlayerX += 1;
				break;
			}
			Arr[PlayerY][PlayerX] = EmptySpace;
			PlayerX += 1;
			break;
		case 'f':
			Arr[PlayerY][PlayerX] = Bomb;
			break;
		default:
			break;
		}
		Sleep(200);
	}
}

