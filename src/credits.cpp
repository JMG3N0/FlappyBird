#include "credits.h"

void InitCredits(Vector2 screenSize, creditsText& Developer, creditsText& Forker, creditsText& Artist, creditsText& Musician)
{

	float gap = screenSize.y * 0.15f;

	Developer.text = "Developer: Ivan Abraham";
	Developer.fontSize = 20.0f;
	Developer.textLength = MeasureText(Developer.text, static_cast<int>(Developer.fontSize));
	Developer.position = { (screenSize.x / 2.0f) - (Developer.textLength / 2.0f), Developer.fontSize + gap};
	
	Forker.text = "Developer: Joan Manuel Rivas Cepeda";
	Forker.fontSize = 20.0f;
	Forker.textLength = MeasureText(Forker.text, static_cast<int>(Forker.fontSize));
	Forker.position = { (screenSize.x / 2.0f) - (Forker.textLength / 2.0f), Developer.position.y + gap};

	Artist.text = "Artist: Ivan Abraham";
	Artist.fontSize = 20.0f;
	Artist.textLength = MeasureText(Artist.text, static_cast<int>(Artist.fontSize));
	Artist.position = { (screenSize.x / 2.0f) - (Artist.textLength / 2.0f), (Forker.position.y + gap) };

	Musician.text = "Musician: Ivan Abraham";
	Musician.fontSize = 20.0f;
	Musician.textLength = MeasureText(Musician.text, static_cast<int>(Musician.fontSize));
	Musician.position = { (screenSize.x / 2.0f) - (Musician.textLength / 2.0f), (Artist.position.y + gap) };

}

void UpdateCredits(screen& currentScreen)
{

	if (IsKeyDown(KEY_ESCAPE))
	{

		currentScreen = Menu;

	}

}

void DrawCredits(creditsText& Developer, creditsText& Forker, creditsText& Artist, creditsText& Musician)
{
	
	ClearBackground(BLACK);

	DrawText(Developer.text, static_cast<int>(Developer.position.x), static_cast<int>(Developer.position.y), static_cast<int>(Developer.fontSize), WHITE);
	DrawText(Forker.text, static_cast<int>(Forker.position.x), static_cast<int>(Forker.position.y), static_cast<int>(Forker.fontSize), WHITE);
	DrawText(Artist.text, static_cast<int>(Artist.position.x), static_cast<int>(Artist.position.y), static_cast<int>(Artist.fontSize), WHITE);
	DrawText(Musician.text, static_cast<int>(Musician.position.x), static_cast<int>(Musician.position.y), static_cast<int>(Musician.fontSize), WHITE);

	DrawText("Press ESC to go back to the main menu", 15, static_cast<int>(Musician.fontSize * 1.5f), static_cast<int>(Musician.fontSize), LIGHTGRAY);
	


}