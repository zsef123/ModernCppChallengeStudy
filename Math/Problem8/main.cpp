#include <gsl/gsl>
#include <iostream>
#include <string>
#include <math.h>
#define uint uint32_t

// Write a program that prints all Armstrong numbers with three digits.

// Make lookup table in each digits.
bool isArmstrong(int x) {
    std::string digits = std::to_string(x);
    int out = 0;
    for (auto d : digits) {
        // int i = std::stoi(d);
        int i = d - '0';
        out += uint(pow(i, digits.length()));
    }
    return (x == out);
}

void printArmstrong() {
    for (int i = 100; i <= 999; i++) {
        if (isArmstrong(i))
            printf("%d ", i);
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    printArmstrong();
    return 0;
}
