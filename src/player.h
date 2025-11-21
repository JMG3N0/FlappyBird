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
		bool alive;
	};

	void InitPlayer(Vector2 screenSize, player& bird, bool multiplayer, player& bird2);
	void UpdatePlayer(player& bird, player& bird2);
	void DrawPlayer(player& p1, player& p2);


}