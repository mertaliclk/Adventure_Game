#include "randgen.h"
#include <cstdlib>
#include <ctime>

RandGen::RandGen() {
    srand(time(0));
}

void RandGen::SetSeed(int seed) {
    srand(seed);
}

int RandGen::RandInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

double RandGen::RandReal(double min, double max) {
    return min + (max - min) * (double)rand() / RAND_MAX;
} 