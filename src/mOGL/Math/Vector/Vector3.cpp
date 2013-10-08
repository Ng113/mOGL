#include "Vector3.h"
#include "math.h"

using namespace mOGL;

Vector3::Vector3()
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}
Vector3::Vector3( float* data )
{
	this->x = data[0];
	this->y = data[1];
	this->z = data[2];
}
Vector3::Vector3( float x , float y , float z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}
float*	Vector3::ptr( float* data )
{
	data[0] = this->x;
	data[1] = this->y;
	data[2] = this->z;
	return data;
}
Vector3 Vector3::dot( const Vector3 &num1 )
{
	return Vector3( num1.x *x , num1.y *y , num1.z *z ); 
}
Vector3 Vector3::cross( const Vector3 &num1 )
{
	return Vector3( y*num1.z - z*num1.y , z*num1.x - x*num1.z , x*num1.y - y*num1.x );
}
float	Vector3::lenght()
{
	return sqrt( x*x + y*y + z*z );
}
Vector3	Vector3::normalize()
{
	Vector3 temp(x,y,z);
	float len = temp.lenght();
	if( len == 0.0 ) return temp;
	temp.x = temp.x / len;
	temp.y = temp.y / len;
	temp.z = temp.z / len;

	return temp;
}
void Vector3::normalized()
{
	float len = lenght();
	if( len == 0.0 ) return ;
	x = x / len;
	y = y / len;
	z = z / len;
}