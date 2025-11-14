#pragma once
#include "game.h"
#include "credits.h"
#include "screenInstances.h"

struct button
{

	Vector2 size;
	Vector2 position;

};

void InitMenu(Vector2 screenSize, button& title, button& start, button& credits, button& quit);
void UpdateMenu( screen& currentScreen, button& start, button& credits, button& quit);
void DrawMenu(button& title, button& start, button& credits, button& quit); 