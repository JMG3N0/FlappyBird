#pragma once
#include "physics.h"

namespace flappy {
	struct player
	{

		Vector2 size;
		Vector2 position;
		float speed;
		float velocity;
		float gravity;

	};

	void InitPlayer(Vector2 screenSize, player& Bird);
	void UpdatePlayer(player& bird);
	void DrawPlayer(player& p1);


}