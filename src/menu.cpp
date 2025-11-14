#include "menu.h"

void InitMenu(Vector2 screenSize, button& title, button& start, button& credits, button& quit)
{

	float gap = screenSize.y * 0.10f;

	title.size.x = screenSize.x * 0.75f;
	title.size.y = screenSize.x * 0.12f;
	title.position.x = (screenSize.x / 2.0f) - (title.size.x / 2.0f);
	title.position.y = gap;


	start.size.x = screenSize.x * 0.20f;
	start.size.y = screenSize.y * 0.10f;
	start.position.x = (screenSize.x / 2.0f) - (start.size.x / 2.0f);
	start.position.y = title.position.y + title.size.y + gap;

	credits.size.x = screenSize.x * 0.20f;
	credits.size.y = screenSize.y * 0.10f;
	credits.position.x = (screenSize.x / 2.0f) - (start.size.x / 2.0f);
	credits.position.y = start.position.y + start.size.y + gap;

	quit.size.x = screenSize.x * 0.20f;
	quit.size.y = screenSize.y * 0.10f;
	quit.position.x = (screenSize.x / 2.0f) - (start.size.x / 2.0f);
	quit.position.y = credits.position.y + credits.size.y + gap;

}

void UpdateMenu( screen& currentScreen, button& start, button& credits, button& quit )
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
	DrawText("Flappy Bird", static_cast<int>(title.position.x + 30.0f), static_cast<int>(title.position.y), static_cast<int>(title.size.y), WHITE);
	DrawRectangleV(start.position, start.size, BLACK);
	DrawText("Play", static_cast<int>(start.position.x + 30.0f), static_cast<int>(start.position.y), static_cast<int>(start.size.y), WHITE);
	DrawRectangleV({credits.position.x - 10.0f, credits.position.y}, { credits.size.x + 50.0f, credits.size.y }, BLACK);
	DrawText("Credits", static_cast<int>(credits.position.x), static_cast<int>(credits.position.y), static_cast<int>(credits.size.y), WHITE);
	DrawRectangleV(quit.position, quit.size, BLACK);
	DrawText("Exit", static_cast<int>(quit.position.x + 30.0f), static_cast<int>(quit.position.y), static_cast<int>(quit.size.y), WHITE);
}