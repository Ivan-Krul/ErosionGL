#include <iostream>
#include "FilePPM.h"
#include "Perlin.h"

int main()
{
    int size = 256;

    Perlin p;
    srand(time(NULL));
    float *ar = p.generate2d(size, size);
    float *arr = p.noise2d(size, size, ar, 8,2.0);

    FilePPM ppm(size, size);
    for(int x = 0; x < size; x++)
    {
        for(int y = 0; y < size; y++)
            ppm.dot(x, y) = 
            { (unsigned char)(arr[x + y*size] * 256.0f),(unsigned char)(arr[x + y * size] * 256.0f),(unsigned char)(arr[x + y * size] * 256.0f) };
    }
    ppm.save("2d.ppm");

    delete[] arr;
    return 0;
}