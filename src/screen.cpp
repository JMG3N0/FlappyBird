#include "screen.h"

void InitScreen()
{
	const char* currentVer = "Ver 0.3";
	int verLength = MeasureText(currentVer, 30);
	bool isPlaying = true;
	Vector2 screenSize = { 980, 600 };

	InitWindow(screenSize.x, screenSize.y, "FlappyBird");
	
	player bird;

	obstacle pipe1;
	obstacle pipe2;

	button title;
	button start;
	button credits;
	button quit;

	creditsText developer;
	creditsText artist;
	creditsText musician;

	screen currentScreen;
	currentScreen = Menu;


	InitGame(screenSize, bird, pipe1, pipe2);
	InitMenu(screenSize, title, start, credits, quit);
	InitCredits(screenSize, developer, artist, musician);

	while (isPlaying)
	{
		switch (currentScreen)
		{

		case Menu:

			UpdateMenu(screenSize, currentScreen, start, credits, quit);

			BeginDrawing();

			DrawMenu(title, start, credits, quit);

			DrawText(currentVer, ( verLength ), (screenSize.y - 30), 30, RED);

			EndDrawing();	

			break;


		case Game:

			UpdateGame(screenSize, currentScreen, bird, pipe1, pipe2);

			BeginDrawing();

			DrawGame(screenSize, bird, pipe1, pipe2);

			EndDrawing();

			break;


		case Credits:

			UpdateCredits(currentScreen);

			BeginDrawing();

			DrawCredits(developer, artist, musician);
				
			EndDrawing();

			break;


		case Quit:

			isPlaying = false;

			return;

		}

	}


}