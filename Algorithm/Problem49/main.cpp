#include <gsl/gsl>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

auto text_histogram(std::string txt) {
    std::unordered_map<char, int> map;    
    for (auto s : txt) {
        if (std::isalpha(s))
            map[s]++;
    }
    int total = 0;
    for (auto m : map)
        total += m.second;

    return map;
}
int main(int argc, char* argv[])
{
    std::string txt = "Text histogram";
    auto hist = text_histogram(txt);
    for (auto h : hist) {
        std::cout << h.first << " : " << h.second << "\n";
    }
    return 0;
}
