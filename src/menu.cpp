#include "menu.h"

void InitMenu(Vector2 screenSize, button& title, button& start, button& credits, button& quit)
{

	float gap = screenSize.y * 0.10;

	title.size.x = screenSize.x * 0.75;
	title.size.y = screenSize.x * 0.12;
	title.position.x = (screenSize.x / 2) - (title.size.x / 2);
	title.position.y = gap;


	start.size.x = screenSize.x * 0.20;
	start.size.y = screenSize.y * 0.10;
	start.position.x = (screenSize.x / 2) - (start.size.x / 2);
	start.position.y = title.position.y + title.size.y + gap;

	credits.size.x = screenSize.x * 0.20;
	credits.size.y = screenSize.y * 0.10;
	credits.position.x = (screenSize.x / 2) - (start.size.x / 2);
	credits.position.y = start.position.y + start.size.y + gap;

	quit.size.x = screenSize.x * 0.20;
	quit.size.y = screenSize.y * 0.10;
	quit.position.x = (screenSize.x / 2) - (start.size.x / 2);
	quit.position.y = credits.position.y + credits.size.y + gap;

}

void UpdateMenu(Vector2 screenSize, screen& currentScreen, button& start, button& credits, button& quit )
{

	Vector2 mousePosition = GetMousePosition();

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
		&& PointRecColition(mousePosition, start.size, start.position))
	{

		currentScreen = Game;

	}

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
		&& PointRecColition(mousePosition, credits.size, credits.position))
	{

		currentScreen = Credits;

	}

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
		&& PointRecColition(mousePosition, quit.size, quit.position))
	{

		currentScreen = Quit;

	}

}

void DrawMenu(button& title, button& start, button& credits, button& quit)
{

	ClearBackground(RAYWHITE);

	DrawRectangleV(title.position, title.size, BLACK);
	DrawRectangleV(start.position, start.size, BLACK);
	DrawRectangleV(credits.position, credits.size, BLACK);
	DrawRectangleV(quit.position, quit.size, BLACK);
}