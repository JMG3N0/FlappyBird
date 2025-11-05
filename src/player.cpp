#include "player.h"

void InitPlayer(Vector2 screenSize, player &bird)
{
	bird.size.x = screenSize.x * 0.10;
	bird.size.y = screenSize.y * 0.10;
	bird.position.y = screenSize.y *0.5 - bird.size.y / 2;
	bird.position.x = screenSize.x * 0.25 - bird.size.x;
	bird.speed = 400;
	bird.gravity = 150;

}

void UpdatePlayer(Vector2 screenSize, player& bird)
{

	if (bird.position.y > 0)
	{

		if (IsKeyDown(KEY_W))
		{

			bird.position.y = bird.position.y - bird.speed * GetFrameTime();

		}

	}

	bird.position.y = bird.position.y + bird.gravity * GetFrameTime();

}

void DrawPlayer(player& p1)
{

	DrawRectangleV(p1.position, p1.size, BLACK);

}