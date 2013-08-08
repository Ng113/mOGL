#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#include <sstream>
#include <string>

namespace mOGL
{
	class String : public std::string
	{
	public:
		String( const std::string  &str1 );
		friend std::string operator+( const std::string  &str1, const std::string &str2 )
		{
			std::string str = str1;
			str.append( str2 );
			return str;
		}
		friend std::string operator+( const std::string  &str1, const int &num )
		{
			std::stringstream tempStr( "" );
			tempStr << str1 << num ; 
			return tempStr.str();
		}

		friend std::string operator+( const int &num , const std::string  &str1 )
		{
			std::stringstream tempStr( "" );
			tempStr << num << str1;
			return tempStr.str();
		}

		friend std::string operator+( const std::string  &str1, const float &num )
		{
			std::stringstream tempStr( str1 );
			tempStr << num ;
			return tempStr.str();
		}

		friend std::string operator+( const float &num , const std::string  &str1 )
		{
			std::stringstream tempStr( "" );
			tempStr << num << str1;
			return tempStr.str();
		}
	};

}

#endif