#pragma once
#include "raylib.h"

struct player
{

	Vector2 size;
	Vector2 position;
	float speed;
	float velocity;

};

void InitPlayer(Vector2 screenSize, player& Bird);
void UpdatePlayer(player& P1);
void DrawPlayer(player& p1);


