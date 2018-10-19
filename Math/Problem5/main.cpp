#include <gsl/gsl>
#include <vector>
#define uint unsigned int
// Write a program that prints all the sexy prime pairs up to a limit entered by the user.

void printSexyPrime(uint x) {
    std::vector<bool> eratos(x + 1, true);
    eratos[0] = eratos[1] = false;

    for (uint i = 2; i <= x; i++) {
        if (!eratos[i])
            continue;
        for (uint j = i + i; j <= x ; j += i)
            eratos[j] = false;
    }

    for (uint i = 2 ; i <= (x - 6); i++) { 
        if (eratos[i] && eratos[i + 6])
            printf("%d %d\n", i, i + 6);
    }
}


int main(int argc, char* argv[])
{
    uint x;
    printf("input : "); scanf("%d", &x);

    printSexyPrime(x);
    return 0;
}
