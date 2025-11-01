#include "screen.h"

void InitScreen()
{
	Vector2 screenSize = { 980, 600 };

	InitWindow(screenSize.x, screenSize.y, "FlappyBird");
	player bird;
	InitGame(screenSize, bird);

	while (!WindowShouldClose())
	{

		UpdateGame(screenSize, bird);

		BeginDrawing();

		DrawGame(screenSize, bird);

		EndDrawing();

	}


}