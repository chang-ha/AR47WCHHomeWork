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
    int Att = 10;
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

void Damage(const char* const _AttName,  // 공격자_이름 
    const char* const _DefName,          // 방어자_이름
    const int& _Attacker_Att,            // 공격자_공격력
    int& _Defender_HP)                   // 방어자_체력
{
    _Defender_HP -= _Attacker_Att;
    system("cls");
    StatusRender("Player", NewPlayer.Att, NewPlayer.HP);
    StatusRender("Monster", NewMonster.Att, NewMonster.HP);
    printf_s("%s공격을 시작합니다\n", _AttName);
    printf_s("%s가 %d의 데미지를 입었습니다\n", _DefName, _Attacker_Att);
}

int main()
{
    StatusRender("Player", NewPlayer.Att, NewPlayer.HP);
    _getch();
    StatusRender("Monster", NewMonster.Att, NewMonster.HP);
    _getch();
    while (NewPlayer.HP && NewMonster.HP != 0)
    {
        system("cls");
        switch (NewPlayer.HP == 0)
        {
        case true:
            printf_s("플레이어가 죽었습니다.\n");
            printf_s("몬스터의 승리입니다.\n");
            _getch();
            break;
        default:
            Damage("Player", "Monster", NewPlayer.Att, NewMonster.HP);
            _getch();
            break;
        }
        switch (NewMonster.HP == 0)
        {
        case true:
            printf_s("몬스터가 죽었습니다.\n");
            printf_s("플레이어의 승리입니다.\n");
            _getch();
            break;
        default:
            Damage("Monster", "Player", NewMonster.Att, NewPlayer.HP);
            _getch();
            break;
        }
    }
}
