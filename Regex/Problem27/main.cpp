#include <gsl/gsl>
#include <vector>
#include <iostream>

#include <boost/tokenizer.hpp>
// Splitting a string into tokens with a list of possible delimiters.

auto split_string(const std::string &input, const std::string &delimiter) {
    std::vector<std::string> output;
    boost::char_separator<char> seq(delimiter.c_str());
    boost::tokenizer<boost::char_separator<char>> tokens(input, seq);

    for (const auto &t : tokens)
        output.push_back(t);
    return output;
}

int main(int argc, char* argv[])
{
    std::string input = "this,is.a sample!!";
    std::string delim = ",.! ";
    auto output = split_string(input, delim);
    for (const auto &o : output) 
        std::cout << o << " | ";
    return 0;
}
