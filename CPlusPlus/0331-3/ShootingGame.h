#pragma once
//#include "Player.h"
//#include "Monster.h"

class Player;
class Monster;
class ShootingGame
{
public:
	static void Loading();
	static void GameUpdate();
	static void MonsterMove();
	static void Collision();

	static void PlayerDeathCehck();
	static void GameProgress();

private:
	static Player NewPlayer;

	ShootingGame() {
	}
};