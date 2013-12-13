#pragma once

class Vector2d
{
public:
	float x;
	float y;

	Vector2d():x(0),y(0)
	{
	}
	Vector2d(float x,float y):x(x),y(y)
	{
	}
	float X() const { return x; }
	void X(float val) { x = val; }
	float Y() const { return y; }
	void Y(float val) { y = val; }
	float getLenght() const;
	Vector2d operator+(const Vector2d& v2);
	Vector2d operator-(const Vector2d& v2);
	Vector2d operator*(float c);
	bool operator>(const Vector2d& v2);
	bool operator<(const Vector2d& v2);
	Vector2d normalize();
};
