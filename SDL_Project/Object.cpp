#include "Object.h"
#include "CFPS.h"

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

bool Object::isCollide( const Object& object )
{
	typedef Vector2D<float> Distance;

	Geometry::Position new_position = GetNextPosition(FPS::Instance()->getSpeedFactor());
	Geometry::Position new_center_position = Geometry::Position(new_position.x + size_.x / 2, new_position.y + size_.y / 2);
	Distance c_c = object.getCenter() - new_center_position;
	float s_s = object.getSize().x * 0.5f + getSize().y * 0.5f;
	return c_c.getLenght() - s_s <= 0;
}