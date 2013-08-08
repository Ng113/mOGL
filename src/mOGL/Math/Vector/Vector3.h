#ifndef __VECTOR3_H__
#define __VECTOR3_H__

namespace mOGL
{
	class Vector3
	{
		public:
			Vector3();
			Vector3( float x , float y , float z );

			Vector3 dot( const Vector3 &num1 );
			Vector3 cross( const Vector3 &num1 );
			float	lenght();
			Vector3	normalize();
			void	normalized();
			
			/*
				實在是太鳥了 竟然一定要寫在header file 
				改天再研究怎麼移到 cpp file
			*/
			friend Vector3 operator+(const Vector3  &num1, const Vector3 &num2)
			{
				return Vector3( num1.x + num2.x , num1.y + num2.y , num1.z + num2.z ); 
			}
			friend Vector3 operator-(const Vector3  &num1, const Vector3 &num2)
			{
				return Vector3( num1.x - num2.x , num1.y - num2.y , num1.z - num2.z ); 
			}
			friend Vector3 operator*(const Vector3  &num1, const float &num2)
			{
				return Vector3( num1.x *num2 , num1.y *num2 , num1.z *num2 ); 
			}
			friend Vector3 operator*(const float &num1 , const Vector3  &num2)
			{
				return Vector3( num2.x *num1 , num2.y *num1 , num2.z *num1 ); 
			}
		public:
			float x,y,z;
	};
}

#endif

