#include "obstacle.h"

void InitObstacles(Vector2 screenSize, obstacle& pipe1)
{
	
	
	pipe1.gap = screenSize.y * 0.3f;
	
	pipe1.size.x = screenSize.x * 0.1f;
	pipe1.size.y = screenSize.y * 0.75f;
	
	pipe1.position.x = screenSize.x;
	pipe1.position.y = (screenSize.y * 0.5f) + (pipe1.size.y * 0.2f);
	
	pipe1.mirrorPosition.x = pipe1.position.x;
	pipe1.mirrorPosition.y = pipe1.position.y - pipe1.size.y - pipe1.gap;

	
}

void UpdateObstacles(Vector2 screenSize, obstacle& pipe1)
{

	float speed = 200.0f;

	pipe1.position.x = pipe1.position.x - (speed * GetFrameTime());
	pipe1.mirrorPosition.x = pipe1.position.x;
	/*
	pipe2.position.x = pipe2.position.x - (speed * GetFrameTime());
	*/

	if (pipe1.position.x + pipe1.size.x <= 0.0f)
	{

		float variability = static_cast<float>(GetRandomValue(0, static_cast<int>((screenSize.y * 0.25f))));

		pipe1.position.x = screenSize.x;
		pipe1.position.y = (screenSize.y * 0.5f) + (pipe1.size.y * 0.2f) - variability;
		pipe1.mirrorPosition.y = pipe1.position.y - pipe1.size.y - pipe1.gap;

	}

}

void DrawObstacle(obstacle& pipe1)
{

	DrawRectangleV(pipe1.position, pipe1.size, BLACK);
	DrawRectangleV(pipe1.mirrorPosition, pipe1.size, BLACK);
	
}