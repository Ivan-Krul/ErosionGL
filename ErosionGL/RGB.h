#pragma once
#include <initializer_list>
struct RGB
{
	unsigned char r, g, b;
	RGB operator= (std::initializer_list<unsigned char> inilist_)
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
		return *this;
	}
	RGB operator=(RGB other_)
	{
		r = other_.r;
		g = other_.g;
		b = other_.b;
		return *this;
	}
	RGB operator+(RGB other_)
	{
		r += other_.r;
		g += other_.g;
		b += other_.b;
		return *this;
	}
	RGB operator-(RGB other_)
	{
		r -= other_.r;
		g -= other_.g;
		b -= other_.b;
		return *this;
	}
	RGB operator*(RGB other_)
	{
		r *= other_.r;
		g *= other_.g;
		b *= other_.b;
		return *this;
	}
	RGB operator/(RGB other_)
	{
		if(other_.r == 0) other_.r++;
		if(other_.g == 0) other_.g++;
		if(other_.b == 0) other_.b++;
		r /= other_.r;
		g /= other_.g;
		b /= other_.b;
		return *this;
	}
	RGB operator=(unsigned char other_)
	{
		r = other_;
		g = other_;
		b = other_;
		return *this;
	}
	RGB operator+(unsigned char other_)
	{
		r += other_;
		g += other_;
		b += other_;
		return *this;
	}
	RGB operator-(unsigned char other_)
	{
		r -= other_;
		g -= other_;
		b -= other_;
		return *this;
	}
	RGB operator*(unsigned char other_)
	{
		r *= other_;
		g *= other_;
		b *= other_;
		return *this;
	}
	RGB operator/(unsigned char other_)
	{
		if(other_ == 0) other_++;
		r /= other_;
		g /= other_;
		b /= other_;
		return *this;
	}
};

