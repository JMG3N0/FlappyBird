#include "game.h"

void InitGame(Vector2 screensize)
{

	InitPlayer(screensize);

}

void UpdateGame(Vector2 screensize)
{

	UpdatePlayer(Bird);

}

void DrawGame(Vector2 screenSize)
{

	DrawPlayer(Bird.position, Bird.size);

}