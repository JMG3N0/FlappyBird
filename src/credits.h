#include "physics.h"
#include "screenInstances.h"

struct creditsText
{
	const char* text;
	Vector2 position;
	int textLength;
	float fontSize;

};

void InitCredits(Vector2 screenSize, creditsText& Developer, creditsText& Artist, creditsText& Musician);
void UpdateCredits(screen& currentScreen);
void DrawCredits(creditsText& Developer, creditsText& Artist, creditsText& Musician);
