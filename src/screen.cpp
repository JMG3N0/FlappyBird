#include "screen.h"

void InitScreen()
{
	Vector2 screenSize = { 980, 600 };

	InitWindow(screenSize.x, screenSize.y, "FlappyBird");
	
	player bird;

	obstacle pipe1;
	obstacle pipe2;

	button title;
	button start;
	button credits;
	button quit;

	screen currentScreen;
	currentScreen = Menu;

	InitGame(screenSize, bird, pipe1, pipe2);
	InitMenu(screenSize, title, start, credits, quit);

	while (!WindowShouldClose())
	{
		switch (currentScreen)
		{

		case Menu:

			UpdateMenu(screenSize, currentScreen, start, credits, quit);

			BeginDrawing();

			DrawMenu(title, start, credits, quit);

			EndDrawing();

			break;


		case Game:

			UpdateGame(screenSize, bird, pipe1, pipe2);

			BeginDrawing();

			DrawGame(screenSize, bird, pipe1, pipe2);

			EndDrawing();

			break;


		case Credits:



			break;


		case Quit:

			return;

		}

	}


}