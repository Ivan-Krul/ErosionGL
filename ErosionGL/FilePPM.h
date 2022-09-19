#pragma once
#include <fstream>
#include <vector>
#include <cassert>
#include "RGB.h"
class FilePPM
{
	unsigned short _x;
	unsigned short _y;
	std::vector<RGB> _pic;

public:
	FilePPM(unsigned short x_, unsigned short y_);
	void clear();
	RGB &dot(unsigned short x_, unsigned short y_);
	unsigned short sizex();
	unsigned short sizey();
	void save(std::string dir_);
	void save_e(std::string dir_);
	bool load(std::string dir_);
	bool load_d(std::string dir_);
};

