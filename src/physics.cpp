#include "physics.h"
namespace flappy {
	bool RectangelColition(Vector2 size1, Vector2 position1, Vector2 size2, Vector2 position2)
	{

		if (position1.y + size1.y > position2.y
			&& position1.y < position2.y + size2.y
			&& position1.x + size1.x > position2.x
			&& position1.x < position2.x + size2.x)
		{

			return true;

		}
		else
		{

			return false;

		}

	}

	bool PointRecColition(Vector2 point, Vector2 recSize, Vector2 recPos)
	{
		if (point.x > recPos.x
			&& point.x < recPos.x + recSize.x
			&& point.y > recPos.y
			&& point.y < recPos.y + recSize.y)
		{

			return true;

		}
		else
		{

			return false;

		}
	}
}