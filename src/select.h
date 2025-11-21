#pragma once
#include "screenInstances.h"
#include "raylib.h"


namespace flappy {

	bool UpdateSelect(screen& currentScreen, Vector2 screenSize);
	void DrawSelect(Vector2 screenSize);

}