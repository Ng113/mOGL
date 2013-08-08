#include "Vector2.h"
#include "math.h"

using namespace mOGL;

Vector2::Vector2()
{
	this->x = 0.0;
	this->y = 0.0;
}
Vector2::Vector2( float x , float y)
{
	this->x = x;
	this->y = y;
}

Vector2 operator+(const Vector2  &num1, const Vector2 &num2)
{
	return Vector2( num1.x + num2.x , num1.y + num2.y ); 
}
Vector2 operator-(const Vector2  &num1, const Vector2 &num2)
{
	return Vector2( num1.x - num2.x , num1.y - num2.y ); 
}
Vector2 operator*(const Vector2  &num1, const float &num2)
{
	return Vector2( num1.x *num2 , num1.y *num2 ); 
}

Vector2 operator*(const float &num1 , const Vector2  &num2)
{
	return Vector2( num2.x *num1 , num2.y *num1 ); 
}
float	Vector2::lenght()
{
	return sqrt( x*x + y*y );
}
Vector2	Vector2::normalize()
{
	Vector2 temp(x,y);
	float len = temp.lenght();
	if( len == 0.0 ) return temp;
	temp.x = temp.x / len;
	temp.y = temp.y / len;

	return temp;
}
void Vector2::normalized()
{
	float len = lenght();
	if( len == 0.0 ) return ;
	x = x / len;
	y = y / len;
}