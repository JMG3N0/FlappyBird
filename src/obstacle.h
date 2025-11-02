#pragma once
#include "raylib.h"

struct obstacle
{

	Vector2 size;
	Vector2 position;
	Vector2 mirrorPosition;
	float gap;

};

void InitObstacles(Vector2 screenSize, obstacle& pipe1, obstacle& pipe2);
void UpdateObstacles(Vector2 screenSize, obstacle& pipe1, obstacle& pipe2);
void DrawObstacle(obstacle& pipe1, obstacle& pipe2);