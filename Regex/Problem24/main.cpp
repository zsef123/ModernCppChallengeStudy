#include <gsl/gsl>
#include <vector>
#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>
/*
String to binary conversion
Write a function that, given a string containing hexadecimal digits as the input argument,
returns a vector of 8-bit integers that represent the numerical deserialization of the string content. Th
following are examples:
Input: "BAADF00D"or "baadF00D", output: {0xBA, 0xAD, 0xF0, 0x0D}
Input "010203040506", output: {1, 2, 3, 4, 5, 6}
*/

auto str2hex(std::string &input) {
    const char *ptr = input.c_str();
    char buf[3] = {0};
    std::vector<std::string> output;
    size_t max = input.length();
    for (size_t i = 0; i < max - 1; i += 2) {
        if (ptr[i] < '9' && ptr[i+1] < '9'){
            output.push_back(std::string(1, ptr[i + 1]));
        }

        else {
            output.push_back(std::string("0x") + boost::algorithm::to_upper_copy(std::string(ptr + i, 2)));
        }
    } 
    return output;
}

int main(int argc, char* argv[])
{
    std::string a = "BAADF00D";
    std::string b = "baadF00D";
    std::string c = "010203040506";
    
    auto z = str2hex(a);
    for (auto x : z)
        std::cout << x << ", ";
    return 0;
}
