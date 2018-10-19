#include <gsl/gsl>
#include <vector>
#define uint unsigned int

//Write a program that computesand prints the largest prime number that is smaller than a number provided by the user, which must be a positive integer.

uint getLargestPrime(uint x) {
    std::vector<bool> eratos(x + 1, true);
    eratos[0] = eratos[1] = false;

    for (uint i = 2; i <= x; i++) {
        if (!eratos[i])
            continue;
        for (uint j = i + i; j <= x ; j += i)
            eratos[j] = false;
    }
    
    for (uint i = x; i > 0 ; i--) {
        if (eratos[i])
            return i;
    }
}

int main(int argc, char* argv[])
{
    uint x;
    printf("input : "); scanf("%d", &x);

    uint out = getLargestPrime(x);
    printf("out : %d\n", out);
    return 0;
}
