#include <gsl/gsl>
#include <math.h>
#include <vector>
#define uint uint32_t
#define MAXNUM 1000000

// Write a program that prints the list of all pairs of amicable numbers smaller than 1,000,000. 

uint getSumProperDivisor(uint i) {
    uint out = 1;
    for (uint j = 2 ; j < sqrt(i); j++) {
        uint div = int(i / j);
        uint mod = i % j;
        if (mod == 0) {
            if (j == div)
                out += div;
            else
                out += div + j;
        }
    }
    return out;
}
void printAmicable() {
    std::vector<bool> filter(MAXNUM, false);

    std::vector<std::pair<uint, uint>> amicable;

    for (uint i = 2; i < MAXNUM / 2 ; i++) {
        if (filter[i])
            continue;

        uint x = getSumProperDivisor(i);
        uint y = getSumProperDivisor(x);
        if (y == i && x != y) {
            std::pair<uint, uint> tmp(i, x);
            amicable.push_back(tmp);
            filter[i] = filter[x] = true;
        }
    }

    for (auto p : amicable) 
        printf("%d %d\n", p.first, p.second);   
}

int main(int argc, char* argv[])
{
    printAmicable();
    return 0;
}
