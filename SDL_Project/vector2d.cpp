#include "vector2d.h"
#include <math.h>

float Vector2d::getLenght() const
{
	return sqrt(x*x+y*y);
}

Vector2d Vector2d::operator+( const Vector2d& v2 )
{
	Vector2d res;
	res.x=this->x+v2.x;
	res.y=this->y+v2.y;
	return res;
}

Vector2d Vector2d::operator-( const Vector2d& v2 )
{
	Vector2d res;
	res.x=this->x-v2.x;
	res.y=this->y-v2.y;
	return res;
}
Vector2d Vector2d::operator*(float c)
{
	Vector2d res;
	res.x=this->x*c;
	res.y=this->y*c;
	return res;
}

Vector2d Vector2d::normalize()
{
	Vector2d res(0,0);
	if(this->getLenght()>0)
	{
		res.X(this->X()/this->getLenght());
		res.Y(this->Y()/this->getLenght());
	}
	return res;
}

bool Vector2d::operator>( const Vector2d& v2 )
{
	return this->getLenght()>v2.getLenght();
}
bool Vector2d::operator<( const Vector2d& v2 )
{
	return this->getLenght()<v2.getLenght();
}