#pragma once
#include "physics.h"

void InitGame(Vector2 screensize, player& bird, obstacle& pipe1, obstacle& pipe2);
void UpdateGame(Vector2 screensize, player& bird, obstacle& pipe1, obstacle& pipe2);
void DrawGame(Vector2 screenSize, player& bird, obstacle& pipe1, obstacle& pipe2);