#include "credits.h"

void InitCredits(Vector2 screenSize, creditsText& Developer, creditsText& Artist, creditsText& Musician)
{

	float gap = screenSize.y * 0.15;

	Developer.text = "Developer: Ivan Abraham";
	Developer.fontSize = 20;
	Developer.textLength = MeasureText(Developer.text, Developer.fontSize);
	Developer.position = { (screenSize.x / 2) - (Developer.textLength / 2), Developer.fontSize + gap};

	Artist.text = "Artist: Ivan Abraham";
	Artist.fontSize = 20;
	Artist.textLength = MeasureText(Artist.text, Artist.fontSize);
	Artist.position = { (screenSize.x / 2) - (Artist.textLength / 2), (Developer.position.y + gap) };

	Musician.text = "Musician: Ivan Abraham";
	Musician.fontSize = 20;
	Musician.textLength = MeasureText(Musician.text, Musician.fontSize);
	Musician.position = { (screenSize.x / 2) - (Musician.textLength / 2), (Artist.position.y + gap) };

}

void UpdateCredits(screen& currentScreen)
{

	if (IsKeyDown(KEY_ESCAPE))
	{

		currentScreen = Menu;

	}

}

void DrawCredits(creditsText& Developer, creditsText& Artist, creditsText& Musician)
{
	
	ClearBackground(BLACK);

	DrawText(Developer.text, Developer.position.x, Developer.position.y, Developer.fontSize, WHITE);
	DrawText(Artist.text, Artist.position.x, Artist.position.y, Artist.fontSize, WHITE);
	DrawText(Musician.text, Musician.position.x, Musician.position.y, Musician.fontSize, WHITE);

	DrawText("Press ESC to go back to the main menu", 15, Musician.fontSize * 1.5, Musician.fontSize, LIGHTGRAY);
	


}