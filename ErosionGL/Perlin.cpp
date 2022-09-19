#include "Perlin.h"

int Perlin::_rand()
{
    _x = 25214903917 * _x + 11;
    return _x;
}

Perlin::Perlin(unsigned int seed_)
{
    _x = seed_;
}

float *Perlin::noise1d(unsigned int count_, float *seed_, int octav)
{
    float * out = new float[count_];
    for(int x = 0; x < count_; x++)
    {
        float noise = 0.0f;
        float scale = 1.0f;
        float scale_acc = 0.0f;
        for(int o = 0; o < octav; o++)
        {
            int pitch = count_ >> o;
            int sample1 = (x / pitch) * pitch;
            int sample2 = (sample1 + pitch) % count_;

            float blend = float(x - sample1) / float(pitch);
            float sample = (1.0f - blend) * seed_[sample1] + blend * seed_[sample2];
            noise += sample * scale;
            scale_acc += scale;
            scale = scale / 2.0f;
        }
        out[x] = noise / scale_acc;
    }
    return out;
}


