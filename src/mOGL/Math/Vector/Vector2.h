#ifndef __VECTOR2_H__
#define __VECTOR2_H__

namespace mOGL
{
	class Vector2
	{
		public:
			Vector2();
			Vector2( float* data );
			Vector2( float x , float y );

			friend Vector2 operator+(const Vector2  &num1, const Vector2 &num2);
			friend Vector2 operator-(const Vector2  &num1, const Vector2 &num2);
			friend Vector2 operator*(const Vector2  &num1, const float &num2);
			friend Vector2 operator*(const float &num1 , const Vector2  &num2);
			float	lenght();
			Vector2	normalize();
			void	normalized();
		public:
			float x,y;
	};
}

#endif
