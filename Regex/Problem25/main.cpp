#include <gsl/gsl>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <iostream>
/*
Capitializing an article title
*/

auto capitializing(std::string &input) {
    std::string output;
    boost::char_separator<char> seq(" ");
    boost::tokenizer<boost::char_separator<char>> tokens(input, seq);

    for (auto t : tokens) {
        boost::algorithm::to_lower(t);
        if ('a' <= t[0] && t[0] <= 'z')
            t[0] += 'A'-'a';
        t += " ";
        output += t;
    }
    return output;
}

int main(int argc, char* argv[])
{
    std::string input = "tHe c++ chAllEnger";
    std::string output = capitializing(input);
    std::cout << output << "\n";
    return 0;
}
