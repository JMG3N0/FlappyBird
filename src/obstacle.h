#pragma once
#include "physics.h"


namespace flappy {
	struct obstacle
	{

		Vector2 size;
		Vector2 position;
		Vector2 mirrorPosition;
		float gap;

	};

	void InitObstacles(Vector2 screenSize, obstacle& pipe1);
	void UpdateObstacles(Vector2 screenSize, obstacle& pipe1);
	void DrawObstacle(obstacle& pipe1);
}