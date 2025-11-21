#include "select.h"
#include "menu.h"


namespace flappy {


	bool UpdateSelect(screen& currentScreen, Vector2 screenSize)
	{
		Vector2 mousePosition = GetMousePosition();

		//P1
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
			&& mousePosition.x < (screenSize.x/2.0f))
		{

			currentScreen = Game;
			return false;

		}
		//P2
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
			&& mousePosition.x > (screenSize.x / 2.0f))
		{

			currentScreen = Game;
			return true;
		}
		
		if (IsKeyDown(KEY_ESCAPE))
		{

			currentScreen = Menu;

		}
	}

	void DrawSelect(Vector2 screenSize)
	{
		Vector2 mousePosition = GetMousePosition();
		ClearBackground(RAYWHITE);
		DrawText("Press ESC to go back to the main menu", 15, 10, 20, LIGHTGRAY);

		DrawText("1 Player", 50, (static_cast<int>(screenSize.y) / 2), 50, DARKPURPLE);
		DrawText("2 Player", static_cast<int>(screenSize.x - 300.0f), (static_cast<int>(screenSize.y) / 2), 50, DARKBLUE);
		if (mousePosition.x < (screenSize.x / 2.0f))
		{
			DrawText("Player 1 uses the W key", 10, ((static_cast<int>(screenSize.y) / 2) + 60), 20, DARKPURPLE);
		}

		if (mousePosition.x > (screenSize.x / 2.0f))
		{
			DrawText("Player 1 uses the W key", static_cast<int>(screenSize.x - 350.0f), ((static_cast<int>(screenSize.y) / 2) + 60), 20, DARKPURPLE);
			DrawText("Player 2 uses the Up Arrow key", static_cast<int>(screenSize.x - 350.0f), ((static_cast<int>(screenSize.y) / 2) + 100), 20, DARKBLUE);
		}

		
	}



}