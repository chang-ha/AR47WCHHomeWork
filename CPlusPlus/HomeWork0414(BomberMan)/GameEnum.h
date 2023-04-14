#pragma once

enum class ObjectOrder
{
	Bomb, // == 0
	Item,
	Player, // == 1
	// 만약 숫자를 지정하면
	// Bomb = 5 // == 5
	// Player // == 6
};  