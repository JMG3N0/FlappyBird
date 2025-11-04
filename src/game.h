#pragma once
#include "player.h"
#include "obstacle.h"
#include "screenInstances.h"

extern bool gameOver;

void InitGame(Vector2 screensize, player& bird, obstacle& pipe1, obstacle& pipe2);
void UpdateGame(Vector2 screenSize, screen& currentScreen, player& bird, obstacle& pipe1, obstacle& pipe2);
void DrawGame(Vector2 screenSize, player& bird, obstacle& pipe1, obstacle& pipe2);