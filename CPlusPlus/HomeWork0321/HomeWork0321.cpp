#include <iostream>
#include <conio.h>

// HomeWokr0321
// 플레이어와 몬스터의 상태창이 실시간으로 바뀌도록 수정하기

struct Player
{
	int HP = 100;
	int Att = 10;
};

struct Monster
{
	int HP = 100;
	int Att = 20;
};

Player NewPlayer;
Monster NewMonster;

void StatusRender(const char* const _Name, const int& _Att, const int& _HP)
{
	printf_s("----------- %s의 스테이터스 -----------\n", _Name);
	printf_s("공격력 : %d\n", _Att);
	printf_s("체력 : %d\n", _HP);
	printf_s("-------------------------------------------\n");
}

void Damage(const char* const _Attacker_Name,  // 공격자_이름 
	const char* const _Defender_Name,          // 방어자_이름
	const int& _Attacker_Att,            // 공격자_공격력
	int& _Defender_HP)                   // 방어자_체력
{
	_Defender_HP -= _Attacker_Att;
	system("cls");
	StatusRender("Player", NewPlayer.Att, NewPlayer.HP);
	StatusRender("Monster", NewMonster.Att, NewMonster.HP);
	printf_s("%s공격을 시작합니다\n", _Attacker_Name);
	printf_s("%s가 %d의 데미지를 입었습니다\n", _Defender_Name, _Attacker_Att);
	if (_Defender_HP == 0)
	{
		printf_s("%s가 죽었습니다.\n", _Defender_Name);
		printf_s("%s의 승리입니다.\n", _Attacker_Name);
	}
}

int main()
{
	StatusRender("Player", NewPlayer.Att, NewPlayer.HP);
	_getch();
	StatusRender("Monster", NewMonster.Att, NewMonster.HP);
	_getch();
	while (NewPlayer.HP && NewMonster.HP != 0)
	{
		switch (NewPlayer.HP == 0)
		{
		case true:
			break;
		case false:
			Damage("Player", "Monster", NewPlayer.Att, NewMonster.HP);
			_getch();
			break;
		}
		switch (NewMonster.HP == 0)
		{
		case true:
			break;
		case false:
			Damage("Monster", "Player", NewMonster.Att, NewPlayer.HP);
			_getch();
			break;
		}
	}
}
