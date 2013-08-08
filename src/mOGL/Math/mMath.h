#ifndef __MMATH_H__
#define __MMATH_H__

#include "Vector/Vector3.h"
#include "Vector/Vector2.h"

namespace mOGL
{
	void	clear( float matrix[] );
	void	clear( float matrix[] , int row , int column );
	void	set( float matrix[] , int row , int column , float num );
	void	set( float matrix[] , int row , int column , int width , int hieght , float num );
	float	get( float matrix[] , int row , int column );
	float	get( float matrix[] , int row , int column , int width , int hieght );
}

#endif