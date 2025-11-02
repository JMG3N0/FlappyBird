#include "obstacle.h"

void InitObstacles(Vector2 screenSize, obstacle& pipe1, obstacle& pipe2)
{
	
	pipe1.size.x = screenSize.x * 0.1;
	pipe1.size.y = screenSize.y * 0.75;
	pipe1.position.x = screenSize.x;
	pipe1.position.y = (screenSize.y * 0.5) + (pipe1.size.y * 0.2);

	/*
	pipe2.size = pipe1.size;
	pipe2.position.x = pipe1.position.x + (screenSize.x * 0.5);
	pipe2.position.y = pipe1.position.y;
	*/
}

void UpdateObstacles(Vector2 screenSize, obstacle& pipe1, obstacle& pipe2)
{

	float speed = 200;

	pipe1.position.x = pipe1.position.x - (speed * GetFrameTime());
	/*
	pipe2.position.x = pipe2.position.x - (speed * GetFrameTime());
	*/

	if (pipe1.position.x + pipe1.size.x <= 0)
	{

		float variability = GetRandomValue(0, (screenSize.y * 0.25));

		pipe1.position.x = screenSize.x;
		pipe1.position.y = (screenSize.y * 0.5) + (pipe1.size.y * 0.2) - variability;

	}

}

void DrawObstacle(obstacle& pipe1, obstacle& pipe2)
{

	DrawRectangleV(pipe1.position, pipe1.size, BLACK);
	/*
	DrawRectangleV(pipe2.position, pipe2.size, BLACK);
	*/
}