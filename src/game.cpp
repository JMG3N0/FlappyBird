#include "game.h"
namespace flappy {
	bool gameOver = false;

	backGround floor1;
	backGround floor2;
	backGround cloud;
	backGround building1;
	backGround building2;
	backGround buildingFar;

	void InitBackGround(Vector2 screenSize, backGround& downBackgroud1, backGround& downBackgroud2, backGround& upperBackground, backGround& structure1, backGround& structure2, backGround& structure3)
	{

		float layer1Speed = 100;
		float layer2Speed = 70;
		float layer3Speed = 40;

		Vector2 buildingSize = { screenSize.x * 0.09f,screenSize.y * 0.2f };
		Vector2 farBuildingSize = { screenSize.x * 0.04f, screenSize.y * 0.13f };

		downBackgroud1.size = { screenSize.x * 2, screenSize.y };
		downBackgroud1.position.x = 0.0f;
		downBackgroud1.position.y = screenSize.y * 0.85f;
		downBackgroud1.speed = layer1Speed;

		downBackgroud2.size = downBackgroud1.size;
		downBackgroud2.position.x = downBackgroud1.position.x;
		downBackgroud2.position.y = screenSize.y * 0.75f;
		downBackgroud2.speed = layer2Speed;

		upperBackground.size.x = screenSize.x * 0.2f;
		upperBackground.size.y = screenSize.y * 0.1f;
		upperBackground.position.x = screenSize.x;
		upperBackground.position.y = screenSize.y * 0.1f;
		upperBackground.speed = layer3Speed;

		structure1.size = buildingSize;
		structure1.position.x = 0.0f;
		structure1.position.y = floor1.position.y - building1.size.y;
		structure1.speed = layer1Speed;

		structure2.size = buildingSize;
		structure2.position.x = screenSize.x / 2.0f;
		structure2.position.y = building1.position.y;
		structure2.speed = layer1Speed;

		structure3.size = farBuildingSize;
		structure3.position.x = screenSize.x;
		structure3.position.y = downBackgroud2.position.y - buildingFar.size.y;
		structure3.speed = layer2Speed;

	}

	void InitGame(Vector2 screenSize, player& bird, obstacle& pipe1)
	{
		gameOver = false;
		InitPlayer(screenSize, bird);
		InitObstacles(screenSize, pipe1);
		InitBackGround(screenSize, floor1, floor2, cloud, building1, building2, buildingFar);
	}

	void UpdateBackground(Vector2 screenSize, backGround& upperBackground, backGround& structure1, backGround& structure2, backGround& structure3)
	{

		upperBackground.position.x = upperBackground.position.x - upperBackground.speed * GetFrameTime();

		structure1.position.x = structure1.position.x - structure1.speed * GetFrameTime();
		structure2.position.x = structure2.position.x - structure2.speed * GetFrameTime();
		structure3.position.x = structure3.position.x - structure3.speed * GetFrameTime();

		if (structure1.position.x <= 0 - structure1.size.x)
		{

			structure1.position.x = screenSize.x;

		}

		if (structure2.position.x <= 0 - structure2.size.x)
		{

			structure2.position.x = screenSize.x;

		}

		if (structure3.position.x <= 0 - structure3.size.x)
		{

			structure3.position.x = screenSize.x;

		}

	}


	void UpdateGame(Vector2 screenSize, screen& currentScreen, player& bird, obstacle& pipe1)
	{

		if (gameOver)
		{

			if (IsKeyPressed(KEY_SPACE))
			{

				InitGame(screenSize, bird, pipe1);

			}

			if (IsKeyPressed(KEY_ESCAPE))
			{

				InitGame(screenSize, bird, pipe1);

				currentScreen = Menu;

			}

			return;

		}

		UpdateBackground(screenSize, cloud, building1, building2, buildingFar);
		UpdatePlayer(bird);
		UpdateObstacles(screenSize, pipe1);

		if (RectangelColition(bird.size, bird.position, pipe1.size, pipe1.position) || RectangelColition(bird.size, bird.position, pipe1.size, pipe1.mirrorPosition) || bird.position.y >= screenSize.y)
		{

			gameOver = true;

		}

	}

	void DrawBackground(backGround& upperBackground, backGround& structure1, backGround& structure2, backGround& structure3)
	{

		DrawRectangleV(floor2.position, floor2.size, DARKGRAY);
		DrawRectangleV(structure3.position, structure3.size, DARKGRAY);

		DrawRectangleV(floor1.position, floor1.size, LIGHTGRAY);
		DrawRectangleV(structure1.position, structure1.size, LIGHTGRAY);
		DrawRectangleV(structure2.position, structure2.size, LIGHTGRAY);


		DrawRectangleV(upperBackground.position, upperBackground.size, LIGHTGRAY);

	}

	void DrawGame(Vector2 screenSize, player& bird, obstacle& pipe1)
	{

		ClearBackground(RAYWHITE);

		DrawBackground(cloud, building1, building2, buildingFar);
		DrawPlayer(bird);
		DrawObstacle(pipe1);

		if (gameOver)
		{

			DrawRectangle(0, 0, static_cast<int>(screenSize.x), static_cast<int>(screenSize.y), { 0, 0, 0, 128 });

			const char* overText = "Press SPACE to restart the game\n To go back to the menu press ESC";
			int textWidth = MeasureText(overText, 30);
			DrawText(overText, static_cast<int>(screenSize.x * 0.5f - static_cast<float>(textWidth) * 0.5f), static_cast<int>(screenSize.y * 0.5f), 30, RED);

		}

	}

}