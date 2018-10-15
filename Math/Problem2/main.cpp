#include <gsl/gsl>

/*
* GCD
* Write a program that,
* given two positive integers,
* will calculate and print the greatest common divisor of the two.
*/

unsigned int getGcd(unsigned int a, unsigned int b) {
    if (a < b) {
        unsigned int tmp = b;
        b = a;
        a = tmp;
    }

    unsigned int mod = a % b;

    while (mod != 0) {
        a = b;
        b = mod;
        mod = a % b;
    }

    return b;
}

int main(int argc, char* argv[])
{
    unsigned int a, b;
    printf("Input a, b : "); scanf("%d %d", &a, &b);

    unsigned int gcd = getGcd(a, b);
    printf("gcd : %d\n", gcd);
    return 0;
}
