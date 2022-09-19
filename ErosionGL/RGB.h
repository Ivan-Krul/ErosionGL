#pragma once
#include <initializer_list>
struct RGB
{
	unsigned char r, g, b;
	void operator= (std::initializer_list<unsigned char> inilist_)
	{
		int i = 0;
		for(const unsigned char *iter = inilist_.begin(); iter != inilist_.end(); iter++)
		{
			if(i == 0) r = *iter;
			else if(i == 1) g = *iter;
			else if(i == 2)
			{
				b = *iter;
				break;
			}
			i++;
		}
	}
	void operator=(RGB other_)
	{
		r = other_.r;
		g = other_.g;
		b = other_.b;
	}
	void operator+(RGB other_)
	{
		r += other_.r;
		g += other_.g;
		b += other_.b;
	}
	void operator-(RGB other_)
	{
		r -= other_.r;
		g -= other_.g;
		b -= other_.b;
	}
	void operator*(RGB other_)
	{
		r *= other_.r;
		g *= other_.g;
		b *= other_.b;
	}
	void operator/(RGB other_)
	{
		r /= other_.r;
		g /= other_.g;
		b /= other_.b;
	}
};

