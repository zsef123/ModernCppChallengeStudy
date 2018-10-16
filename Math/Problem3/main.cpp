#include <gsl/gsl>

/*
* Write a program that will,
* given two or more positive integers,
* calculate and print the least common multiple of them all.
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

unsigned int getLCM(unsigned int a, unsigned int b) {
    return (a * b) / getGcd(a, b);
}

int main(int argc, char* argv[]) {
    unsigned int a, b;
    printf("Input a, b : "); scanf("%d %d", &a, &b);

    printf("LCM : %d\n", getLCM(a, b));
    return 0;
}
