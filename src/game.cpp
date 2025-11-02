#include "game.h"

void InitGame(Vector2 screenSize, player& bird, obstacle& pipe1, obstacle& pipe2)
{

	InitPlayer(screenSize, bird);
	InitObstacles(screenSize, pipe1, pipe2);
	
}

void UpdateGame(Vector2 screenSize, player& bird, obstacle& pipe1, obstacle& pipe2)
{

	UpdatePlayer(bird);
	UpdateObstacles(screenSize, pipe1, pipe2);

	if (RectangelColition(bird.size, bird.position, pipe1.size, pipe1.position) || RectangelColition(bird.size, bird.position, pipe2.size, pipe2.position))
	{

		InitGame(screenSize, bird, pipe1, pipe2);

	}

}

void DrawGame(Vector2 screenSize, player &bird, obstacle& pipe1, obstacle& pipe2)
{

	ClearBackground(RAYWHITE);

	DrawPlayer(bird);
	DrawObstacle(pipe1, pipe2);

}