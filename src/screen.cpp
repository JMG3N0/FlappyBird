#include "screen.h"

void InitScreen()
{
	Vector2 screenSize = { 980, 600 };

	InitWindow(screenSize.x, screenSize.y, "FlappyBird");
	player bird;

	obstacle pipe1;
	obstacle pipe2;
	
	InitGame(screenSize, bird, pipe1, pipe2);

	while (!WindowShouldClose())
	{

		UpdateGame(screenSize, bird, pipe1, pipe2);

		BeginDrawing();

		DrawGame(screenSize, bird, pipe1, pipe2);

		EndDrawing();

	}


}