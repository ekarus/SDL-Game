#pragma once
#include "Types.h"

class CollisinCheck
{
public:
	/*static bool isRectCollide(Geometry::Rectangle rect1, Geometry::Rectangle rect2)
	{
		bool x_coll = false, y_coll = false;

		if((rect1.x + rect1.w > rect2.x && rect1.x + rect1.w < rect2.x + rect2.w) ||
			(rect1.x < rect2.x + rect2.w && rect1.x > rect2.x))
			x_coll = true;

		if((rect1.y + rect1.h > rect2.y && rect1.y + rect1.h < rect2.y + rect2.h) ||
			(rect1.y < rect2.y + rect2.h && rect1.y > rect2.y))
			y_coll = true;

		return x_coll && y_coll;
	}

	static bool isCircleCollide( float x1, float y1, float r1, float x2, float y2, float r2)
	{
		typedef Vector2D<float> Distance;

		Geometry::Position center_position1 = Geometry::Position(x1, y1);
		Geometry::Position center_position2 = Geometry::Position(x2, y2);

		Distance center_distance = center_position2 - center_position1;
		float collision_distance = r1 + r2;
		return center_distance.getLenght() <= collision_distance;
	}*/
};