#include "Object.h"

//Object::ObjectsList Object::list_;


Geometry::Rect Object::getRect()
{
	Geometry::Rect rect;
	rect.x = position_.x;
	rect.y = position_.y;
	rect.w = size_.x;
	rect.h = size_.y;
	return rect;
}

Geometry::Position Object::getCenter() const
{
	Geometry::Position res;
	res.x = position_.x + size_.x / 2;
	res.y = position_.y + size_.y / 2;
	return res;
}
