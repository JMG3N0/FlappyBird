#include "screen.h"

void InitScreen()
{
	Vector2 screenSize = { 980, 600 };

	InitWindow(screenSize.x, screenSize.y, "FlappyBird");
	InitGame(screenSize);

	while (!WindowShouldClose())
	{

		UpdateGame(screenSize);

	}


}