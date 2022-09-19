#pragma once
#include <cmath>
class Perlin
{
public:
	float *generate1d(unsigned int size_);
	float *generate2d(unsigned int sizex_, unsigned int sizey_);
	float *noise1d(unsigned int count_, float *seed_, int octav, float bias);
	float *noise2d(unsigned int countX_, unsigned int countY_, float *seed_, int octav, float bias);
};

