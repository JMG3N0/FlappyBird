#include "player.h"

void InitPlayer(Vector2 screenSize, player &bird)
{
	bird.size.x = screenSize.x * 0.10;
	bird.size.y = screenSize.y * 0.10;
	bird.position.y = screenSize.y *0.2;
	bird.position.x = screenSize.x * 0.4;
	bird.speed = 400;

}

void UpdatePlayer(player &bird)
{

	if (IsKeyDown(KEY_W))
	{

		bird.position.y = bird.position.y - bird.speed * GetFrameTime();

	}

	if (IsKeyDown(KEY_S))
	{

		bird.position.y = bird.position.y + bird.speed * GetFrameTime();

	}

}

void DrawPlayer(player& p1)
{

	DrawRectangleV(p1.position, p1.size, BLACK);

}