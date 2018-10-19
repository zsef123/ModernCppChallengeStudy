#include <gsl/gsl>
#include <vector>
#include <math.h>
#define uint unsigned int
// Write a program that prints all abundant numbers and their abundance, up to a number entered by the user.

void printAbundant(uint x) {
    std::vector<bool> abudants(x+1, false);

    for (uint i = 2; i <= x ; i++) {
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
        abudants[i] = (i < out);
    }

    for (uint i = 2; i <= x ; i++) {
        if (abudants[i])
            printf("%d ", i);
    }
    printf("\n");
}
int main(int argc, char* argv[])
{
    
    uint x;
    printf("input : "); scanf("%d", &x);

    printAbundant(x);

    return 0;
}
