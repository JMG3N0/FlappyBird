#include "game.h"

void InitGame(Vector2 screensize, player& bird)
{

	InitPlayer(screensize, bird);

}

void UpdateGame(Vector2 screensize, player& bird)
{

	UpdatePlayer(bird);

}

void DrawGame(Vector2 screenSize, player &bird)
{

	ClearBackground(RAYWHITE);

	DrawPlayer(bird);

}