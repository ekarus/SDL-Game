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

template<typename Type>
class Vector2D
{
public:
	typedef Type Type;

	Type x;
	Type y;

	Vector2D():x(0),y(0)
	{
	}

	Vector2D(Type x,Type y):x(x),y(y)
	{
	}

	Type getLenght() const
	{
		return sqrt(x*x + y*y);
	}

	Vector2D operator+(const Vector2D& v2)
	{
		Vector2D res;
		res.x = x + v2.x;
		res.y = y + v2.y;
		return res;
	}

	Vector2D operator-(const Vector2D& v2)
	{
		Vector2D res;
		res.x = x - v2.x;
		res.y = y - v2.y;
		return res;
	}

	Vector2D operator*(Type c)
	{
		Vector2D res;
		res.x = x * c;
		res.y = y * c;
		return res;
	}

	Vector2D normalize()
	{
		Vector2D res(0,0);
		if (getLenght() > 0)
		{
			res.x = x / getLenght();
			res.y = y / getLenght();
		}
		return res;
	}

	bool operator>(const Vector2D& v2)
	{
		return getLenght() > v2.getLenght();
	}

	bool operator<(const Vector2D& v2)
	{
		return getLenght() < v2.getLenght();
	}
};