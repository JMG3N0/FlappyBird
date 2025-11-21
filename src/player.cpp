#include "player.h"
namespace flappy {
	void InitPlayer(Vector2 screenSize, player& bird, bool multiplayer, player& bird2)
	{
		bird.size.x = screenSize.x * 0.10f;
		bird.size.y = screenSize.y * 0.10f;
		bird.position.y = screenSize.y * 0.5f - bird.size.y / 2.0f;
		bird.position.x = screenSize.x * 0.25f - bird.size.x;
		bird.speed = 400.0f;
		bird.gravity = 150.0f;
		bird.alive = true;
		if (multiplayer == true)
		{
			bird2.size.x = screenSize.x * 0.10f;
			bird2.size.y = screenSize.y * 0.10f;
			bird2.position.y = screenSize.y * 0.5f - bird.size.y / 2.0f;
			bird2.position.x = screenSize.x * 0.25f - bird.size.x;
			bird2.speed = 400.0f;
			bird2.gravity = 150.0f;
			bird2.alive = true;
		}
	}

	void UpdatePlayer(player& bird, player& bird2)
	{
		if (bird.alive == true)
		{


			if (bird.position.y > 0.0f)
			{

				if (IsKeyDown(KEY_W))
				{

					bird.position.y = bird.position.y - bird.speed * GetFrameTime();
					if (bird.position.y < 0.0f)
					{
						bird.position.y = 0.0f;
					}
				}

			}
			bird.position.y = bird.position.y + bird.gravity * GetFrameTime();
		}
		
		if (bird2.alive == true)
		{


			if (bird2.position.y > 0.0f)
			{

				if (IsKeyDown(KEY_UP))
				{

					bird2.position.y = bird2.position.y - bird2.speed * GetFrameTime();
					if (bird2.position.y < 0.0f)
					{
						bird2.position.y = 0.0f;
					}
				}

			}
			bird2.position.y = bird2.position.y + bird2.gravity * GetFrameTime();
		}



		

	}

	void DrawPlayer(player& p1, player& p2)
	{
		if (p1.alive== true)
		{
			DrawRectangleV(p1.position, p1.size, DARKPURPLE);
		}
		if (p2.alive == true)
		{
			DrawRectangleV(p2.position, p2.size, DARKBLUE);
		}
		

	}
}