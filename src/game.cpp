#include "game.h"

bool gameOver = false;

void InitGame(Vector2 screenSize, player& bird, obstacle& pipe1, obstacle& pipe2)
{
	gameOver = false;
	InitPlayer(screenSize, bird);
	InitObstacles(screenSize, pipe1, pipe2);
	
}

void UpdateGame(Vector2 screenSize,screen& currentScreen, player& bird, obstacle& pipe1, obstacle& pipe2)
{

	if (gameOver)
	{

		if (IsKeyPressed(KEY_SPACE))
		{

			InitGame(screenSize, bird, pipe1, pipe2);

		}	
		
		if (IsKeyPressed(KEY_ESCAPE))
		{

			currentScreen = Menu;

		}

		return;
	
	}

	UpdatePlayer(screenSize, bird);
	UpdateObstacles(screenSize, pipe1, pipe2);

	if (RectangelColition(bird.size, bird.position, pipe1.size, pipe1.position) || RectangelColition(bird.size, bird.position, pipe1.size, pipe1.mirrorPosition) || bird.position.y >= screenSize.y)
	{

		gameOver = true;

	}

}

void DrawGame(Vector2 screenSize, player &bird, obstacle& pipe1, obstacle& pipe2)
{

	ClearBackground(RAYWHITE);

	DrawPlayer(bird);
	DrawObstacle(pipe1, pipe2);

	if (gameOver)
	{

		DrawRectangle(0, 0, screenSize.x, screenSize.y, { 0, 0, 0, 128 });

		const char* overText = "Press SPACE to restart the game\n To go back to the menu press ESC";
		int textWidth = MeasureText(overText, 30);
		DrawText(overText, screenSize.x * 0.5 - textWidth * 0.5, screenSize.y * 0.5, 30, RED);

	}

}