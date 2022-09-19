#pragma once
#include <cmath>
class Perlin
{
	unsigned int _x = 0;
public:
	Perlin(unsigned int seed_);
	int _rand();
	float* noise1d(unsigned int count_, float *seed_, int octav);

};

