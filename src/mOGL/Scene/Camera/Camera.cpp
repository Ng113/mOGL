#include "Camera.h"
#include <stdlib.h>

using namespace mOGL;

Camera::Camera( std::string name )
{
	mName = name ;
	position = mOGL::Vector3( 0.0 , 0.0 , 0.0 );
	lookDirection = mOGL::Vector3( 0.0 , 0.0 , 1.0 );
	upDirection = mOGL::Vector3( 0.0 , 1.0 , 0.0 );
	windowPos = mOGL::Vector2( 0.0 , 0.0 );
	windowLenght = mOGL::Vector2( 256.0 , 256.0 );
}
Camera::Camera( std::string name , mOGL::Vector3	position , mOGL::Vector3	lookDirection , mOGL::Vector3	upDirection)
{
	mName = name ;
	this->position = position;
	this->lookDirection = lookDirection;
	this->upDirection = upDirection;
	windowPos = mOGL::Vector2( 0.0 , 0.0 );
	windowLenght = mOGL::Vector2( 256.0 , 256.0 );
}
void Camera::move( mOGL::Vector3 translation )
{
	position = position + translation;
}
bool Camera::lookAt( mOGL::Vector3 point )
{
	mOGL::Vector3 dir = (point - position).normalize();
	return setDirection( dir );
}
void Camera::setPosition( mOGL::Vector3 pos )
{
	position = pos;
}
bool Camera::setDirection( mOGL::Vector3 direction )
{
	direction.normalize();
	if( direction.lenght() == 0.0 ) return false;
	
	lookDirection = direction;
	_reCalculateUpDirection();
	return true;
}
bool Camera::setUpDirection( mOGL::Vector3 upDirection )
{
	upDirection.normalize();
	if( upDirection.lenght() == 0.0 ) return false;

	this->upDirection = upDirection;
	_reCalculateUpDirection();
	return true;
}
std::string	  Camera::getName( void )
{
	return mName;	
}

mOGL::Vector3 Camera::getPosition()
{
	return position;
}
mOGL::Vector3 Camera::getDirection()
{
	return lookDirection;
}
mOGL::Vector3 Camera::getUpDirection()
{
	return upDirection;
}
bool Camera::_reCalculateUpDirection()
{
	mOGL::Vector3 n = lookDirection.cross( upDirection );
	mOGL::Vector3 tempDir = n.cross( lookDirection ); 

	if( tempDir.lenght() == 0.0 )
	{
		return false;
	}
	else
	{
		upDirection = tempDir.normalize();
		return true;
	}
}