#include <gsl/gsl>
#include <iostream>
#include <string.h>

#define roman_t std::pair<uint32_t, std::string>


using romat_t2 = std::pair<uint32_t, std::string>;

// Write a program that, given a number entered by the user, prints its Roman numeral equivalent. 
const struct roman_t roman[] = {
    roman_t(1000, "M"),
    roman_t(900,  "CM"),
    roman_t(500,  "D"),
    roman_t(400,  "CD"),
    roman_t(100,  "C"),
    roman_t(90,   "XC"),
    roman_t(50,   "L"),
    roman_t(40,   "XL"),
    roman_t(10,   "X"),
    roman_t(9,    "IX"),
    roman_t(5,    "V"),
    roman_t(4,    "IV"),
    roman_t(1,    "I"),
    roman_t(0,    "Z")
};

auto intToRoman(uint32_t x) {
    std::string out;
    
    for (const roman_t *ptr = roman; ptr->first != 0; ptr++) {
        while (x >= ptr->first) {
            out += ptr->second;
            x -= ptr->first;
        }
    }
    return out;
}

int main(int argc, char* argv[])
{
    uint32_t x;
    printf("input :"); scanf("%d", &x);

    std::string roman = intToRoman(x);
    std::cout << roman << std::endl;
    return 0;
}
