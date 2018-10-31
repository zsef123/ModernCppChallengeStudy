#include <gsl/gsl>
#include <string>
#include <vector>
#include <iostream>
#include <boost/algorithm/string.hpp>
/*
Binary to string conversion
Write a function that, given a range of 8-bit integers (such as an array or vector),
returns a string that contains a hexadecimal representation of the input data.
The function should be able to produce both uppercase and lowercase content.
Here are some input and output examples
input: { 0xBA, 0xAD, 0xF0, 0x0D }, output: "BAADF00D"or "baadf00d"
Input: { 1,2,3,4,5,6 }, output: "010203040506"
*/

auto seq2hex(std::vector<std::string> &input) {
    std::string output;
    for (auto i : input)
        output.append(i.substr(2, 2));
    boost::algorithm::to_upper(output);
    return output;
}

auto seq2hex(std::vector<int> &input) {
    char buf[200] = {0};
    int idx = 0;
    for (auto i : input) {
        sprintf(buf + idx, "%02d", i);
        idx +=2;
    }
    std::string output(buf);
    return output;
}

int main(int argc, char* argv[])
{   
    std::vector<std::string> a = {"0xBA", "0xAD", "0xF0", "0x0D"};
    std::vector<int> b = {1, 2, 3, 4, 5, 6};
    
    auto out_a = seq2hex(a);
    std::cout << out_a << " or " << boost::algorithm::to_lower_copy(out_a) << "\n";
    std::cout << seq2hex(b) << "\n";
    return 0;
}
