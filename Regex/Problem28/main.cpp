#include <gsl/gsl>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// Longest palindromic substring

auto len_palindrome(const std::string &input) {
    uint32_t size = 0;
    if (std::equal(input.begin(), input.begin() + input.size() / 2, input.rbegin()))
        size = input.length();
    return size;
}

auto check_palindrome(const std::vector<std::string> &input) {
    size_t idx = 0, max_l = 0;
    for (size_t i = 0 ; i < input.size(); i++) {
        auto len = len_palindrome(input[i]);
        if (len > max_l) {
            max_l = len;
            idx = i;
        }
    }
    return input[idx];
}

int main(int argc, char* argv[])
{
    std::vector<std::string> input = {"lorel", "asdfzxv", "xzcvzxcv", "saiv", "zzzzxxzzzz"};

    auto output = check_palindrome(input);
    std::cout << output << "\n";
    return 0;
}
