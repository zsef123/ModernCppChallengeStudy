#include <gsl/gsl>
#include <math.h>
#include <vector>
#define uint uint32_t

// Write a program that prints the prime factors of a number entered by the user.
uint printPrimeFactorization(uint x) {
    std::vector<uint> primes;
    if (x % 2 == 0) {
        primes.push_back(2);
        x /= 2;
    }
    else {
        for (int i = 3; i <= sqrt(x); i += 2) {
            while (x % i == 0) {
                primes.push_back(i);
                x /= i;
            }
        }
    }
    if (x > 2)
        primes.push_back(x);
        
    for (auto i : primes)
        printf("%d ", i);
}
int main(int argc, char* argv[])
{
    uint x;
    printf("input : "); scanf("%d", &x);

    printPrimeFactorization(x);
    return 0;
}
