#pragma once

template<typename T>
class Rectangle
{
public:
	T x, y, w, h;

	Rectangle():x(0), y(0), w(0), h(0)
	{
	}

	/*Rectangle(Geometry::Position pos, Geometry::Size size): x(pos.x), y(pos.y), w(size.x), h(size.y)
	{
	}*/

	/*Rectangle(Geometry::Rect rect): x(rect.x), y(rect.y), w(rect.w), h(rect.h)
	{
	}*/
};