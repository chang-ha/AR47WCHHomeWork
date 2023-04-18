#include "Body.h"
#include "GameEngineRandom.h"
#include "ConsoleGameScreen.h"

Body::Body() 
{
	RenderChar = L'��';

	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);
	SetPos({ X, Y });
}

Body::~Body() 
{
}

