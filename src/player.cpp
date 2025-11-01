#include "player.h"

player Bird;

void InitPlayer(Vector2 screenSize)
{

	Bird.position.y = screenSize.y *0.2;
	Bird.position.x = screenSize.x * 0.4;
	Bird.size.x = screenSize.x * 0.10;
	Bird.size.y = screenSize.y * 0.10;
	Bird.speed = 100;

}

void UpdatePlayer(player P1)
{

	if (IsKeyDown(KEY_W))
	{

		P1.position.y = P1.position.y - P1.speed * GetFrameTime();

	}

	if (IsKeyDown(KEY_S))
	{

		P1.position.y = P1.position.y + P1.speed * GetFrameTime();

	}

}

void DrawPlayer(Vector2 position, Vector2 size)
{

	DrawRectangleV(position, size, BLACK);

}