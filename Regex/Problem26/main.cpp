#include <gsl/gsl>
#include <iostream>
#include <string>
#include <vector>

// Joining strings together separated by a delimiter

auto join_string(std::vector<std::string> &input, const std::string &delimeter) {
    std::string output;    
    for (const auto &s : input) {
        output += s;
        output += delimeter;
    }
    return output.substr(0, output.length() - delimeter.length());
}

int main(int argc, char* argv[])
{
    std::vector<std::string> input = {"this", "is", "an", "example"};
    std::string delim = ", ";

    std::string output = join_string(input, delim);
    std::cout << output << "\n";
    return 0;
}
