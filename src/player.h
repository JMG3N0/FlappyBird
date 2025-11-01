#pragma once
#include "physics.h"

struct player
{

	Vector2 size;
	Vector2 position;
	float speed;
	float velocity;

};

void InitPlayer(Vector2 screenSize);
void UpdatePlayer(player P1);
void DrawPlayer(Vector2 position, Vector2 size);

extern player Bird;

