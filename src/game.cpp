#include "game.h"

bool gameOver = false;

backGround floor1;
backGround floor2;
backGround cloud;
backGround building1;
backGround building2;
backGround buildingFar;

void InitBackGround(Vector2 screenSize, backGround& floor1, backGround& floor2, backGround& cloud, backGround& building1, backGround& building2, backGround& buildingFar)
{

	float layer1Speed = 100;
	float layer2Speed = 70;
	float layer3Speed = 40;

	Vector2 buildingSize = { screenSize.x * 0.09,screenSize.y * 0.2 };
	Vector2 farBuildingSize = { screenSize.x * 0.04, screenSize.y * 0.13 };

	floor1.size = { screenSize.x * 2, screenSize.y};
	floor1.position.x = 0;
	floor1.position.y = screenSize.y * 0.85;
	floor1.speed = layer1Speed;

	floor2.size = floor1.size;
	floor2.position.x = floor1.position.x;
	floor2.position.y = screenSize.y * 0.75;
	floor2.speed = layer2Speed;

	cloud.size.x = screenSize.x * 0.2;
	cloud.size.y = screenSize.y * 0.1;
	cloud.position.x = screenSize.x;
	cloud.position.y = screenSize.y * 0.1;
	cloud.speed = layer3Speed;

	building1.size = buildingSize;
	building1.position.x = 0;
	building1.position.y = floor1.position.y - building1.size.y;
	building1.speed = layer1Speed;

	building2.size = buildingSize;
	building2.position.x = screenSize.x / 2;
	building2.position.y = building1.position.y;
	building2.speed = layer1Speed;

	buildingFar.size = farBuildingSize;
	buildingFar.position.x = screenSize.x;
	buildingFar.position.y = floor2.position.y - buildingFar.size.y;
	buildingFar.speed = layer2Speed;

}

void InitGame(Vector2 screenSize, player& bird, obstacle& pipe1, obstacle& pipe2)
{
	gameOver = false;
	InitPlayer(screenSize, bird);
	InitObstacles(screenSize, pipe1, pipe2);
	InitBackGround(screenSize, floor1, floor2, cloud, building1, building2, buildingFar);
}

void UpdateBackground(Vector2 screenSize, backGround& cloud, backGround& building1, backGround& building2, backGround& building3)
{

	cloud.position.x = cloud.position.x - cloud.speed * GetFrameTime();

	building1.position.x = building1.position.x - building1.speed * GetFrameTime();
	building2.position.x = building2.position.x - building2.speed * GetFrameTime();
	building3.position.x = building3.position.x - building3.speed * GetFrameTime();

	if (building1.position.x <= 0 - building1.size.x)
	{

		building1.position.x = screenSize.x;

	}

	if (building2.position.x <= 0 - building2.size.x)
	{

		building2.position.x = screenSize.x;

	}

	if (building3.position.x <= 0 - building3.size.x)
	{

		building3.position.x = screenSize.x;

	}

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

			InitGame(screenSize, bird, pipe1, pipe2);

			currentScreen = Menu;

		}

		return;
	
	}

	UpdateBackground(screenSize, cloud, building1, building2, buildingFar);
	UpdatePlayer(screenSize, bird);
	UpdateObstacles(screenSize, pipe1, pipe2);

	if (RectangelColition(bird.size, bird.position, pipe1.size, pipe1.position) || RectangelColition(bird.size, bird.position, pipe1.size, pipe1.mirrorPosition) || bird.position.y >= screenSize.y)
	{

		gameOver = true;

	}

}

void DrawBackground(backGround& cloud, backGround& building1, backGround& building2, backGround& building3)
{

	DrawRectangleV(floor2.position, floor2.size, DARKGRAY);
	DrawRectangleV(building3.position, building3.size, DARKGRAY);
	
	DrawRectangleV(floor1.position, floor1.size, LIGHTGRAY);
	DrawRectangleV(building1.position, building1.size, LIGHTGRAY);
	DrawRectangleV(building2.position, building2.size, LIGHTGRAY);
	

	DrawRectangleV(cloud.position, cloud.size, LIGHTGRAY);

}

void DrawGame(Vector2 screenSize, player &bird, obstacle& pipe1, obstacle& pipe2)
{

	ClearBackground(RAYWHITE);

	DrawBackground(cloud, building1, building2, buildingFar);
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