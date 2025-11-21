#include "screen.h"

namespace flappy {

	void InitScreen()
	{
		const char* currentVer = " Ver 0.3";
		int verLength = MeasureText(currentVer, 30);
		//bool isPlaying = true;
		Vector2 screenSize = { 980, 600 };

		InitWindow(static_cast<int>(screenSize.x), static_cast<int>(screenSize.y), "FlappyBird");
		SetExitKey(NULL);


		player bird;

		obstacle pipe1;


		button title;
		button start;
		button credits;
		button quit;

		creditsText developer;
		creditsText forker;
		creditsText artist;
		creditsText musician;

		screen currentScreen;
		currentScreen = Menu;


		InitGame(screenSize, bird, pipe1);
		InitMenu(screenSize, title, start, credits, quit);
		InitCredits(screenSize, developer, forker, artist, musician);


		while (!WindowShouldClose())
		{
			switch (currentScreen)
			{

			case Menu:

				UpdateMenu(currentScreen, start, credits, quit);

				BeginDrawing();

				DrawMenu(title, start, credits, quit);

				DrawText(currentVer, static_cast<int>(verLength), static_cast<int>(screenSize.y - 30.0f), 30, RED);

				EndDrawing();

				break;


			case Game:

				UpdateGame(screenSize, currentScreen, bird, pipe1);

				BeginDrawing();

				DrawGame(screenSize, bird, pipe1);

				EndDrawing();

				break;


			case Credits:

				UpdateCredits(currentScreen);

				BeginDrawing();

				DrawCredits(developer, forker, artist, musician);

				DrawText(currentVer, static_cast<int>(verLength), static_cast<int>(screenSize.y - 30.0f), 30, RED);

				EndDrawing();

				break;


			case Quit:

				//isPlaying = false;
				CloseWindow();
				return;

			}

		}


	}
}