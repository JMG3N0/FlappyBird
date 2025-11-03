#pragma once
#include "game.h"

enum screen
{

	Menu,
	Game,
	Credits,
	Quit

};

struct button
{

	Vector2 size;
	Vector2 position;

};

void InitMenu(Vector2 screenSize, button& title, button& start, button& credits, button& quit);
void UpdateMenu(Vector2 screenSize, screen& currentScreen, button& start, button& credits, button& quit);
void DrawMenu(button& title, button& start, button& credits, button& quit); 