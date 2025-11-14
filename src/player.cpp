#include "player.h"

void InitPlayer(Vector2 screenSize, player &bird)
{
	bird.size.x = screenSize.x * 0.10f;
	bird.size.y = screenSize.y * 0.10f;
	bird.position.y = screenSize.y *0.5f - bird.size.y / 2.0f;
	bird.position.x = screenSize.x * 0.25f - bird.size.x;
	bird.speed = 400.0f;
	bird.gravity = 150.0f;

}

void UpdatePlayer(player& bird)
{

	if (bird.position.y > 0.0f)
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