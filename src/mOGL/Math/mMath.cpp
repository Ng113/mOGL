#include "mMath.h"

using namespace mOGL;

void clear( float matrix[] )
{
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			matrix[ i*4 + j ] = 0.0 ;	
		}
	}
}
void clear( float matrix[] , int row , int column )
{
	for(int i=0;i<column;++i)
	{
		for(int j=0;j<row;++j)
		{
			matrix[ i*4 + j ] = 0.0 ;	
		}
	}
}
void set( float matrix[] , int row , int column , float num )
{
	matrix[ column*4 + row ] = num ;
}
void set( float matrix[] , int row , int column , int width , int hieght , float num )
{
	matrix[ column*width + row ] = num ;
}
float get( float matrix[] , int row , int column )
{
	return matrix[ column*4 + row ];
}
float get( float matrix[] , int row , int column , int width , int hieght )
{
	return matrix[ column*width + row ];
}