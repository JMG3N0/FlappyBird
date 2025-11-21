#pragma once
#include "raylib.h"
namespace flappy {
	bool RectangelColition(Vector2 size1, Vector2 position1, Vector2 size2, Vector2 position2);
	bool PointRecColition(Vector2 point, Vector2 recSize, Vector2 recPos);
}