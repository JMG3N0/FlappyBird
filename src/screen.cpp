#include "screen.h"
#include "select.h"

namespace flappy {

	void InitScreen()
	{
		const char* currentVer = " Ver 0.4";
		int verLength = MeasureText(currentVer, 30);
		//bool isPlaying = true;
		Vector2 screenSize = { 980, 600 };

		InitWindow(static_cast<int>(screenSize.x), static_cast<int>(screenSize.y), "FlappyBird");
		SetExitKey(NULL);


		player bird;
		player bird2;

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

		bool multiplayer = false;

		
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

			case SelectScreen:
				multiplayer = UpdateSelect(currentScreen, screenSize);
				InitGame(screenSize, bird, pipe1, bird2, multiplayer);
				BeginDrawing();
				DrawSelect(screenSize);
				
				EndDrawing();

				break;
			case Game:

				UpdateGame(screenSize, currentScreen, bird, pipe1, bird2, multiplayer);

				BeginDrawing();

				DrawGame(screenSize, bird, pipe1, bird2);

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