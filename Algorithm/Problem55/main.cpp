#include <gsl/gsl>
#include <iostream>
#include <vector>
// Zip algorithm

auto zip(std::vector<int> const& a, std::vector<int> const& b) {
    std::vector<std::pair<int, int>> out;    
    size_t small_size = (a.size() > b.size()) ? b.size() : a.size();
    for (size_t i = 0; i < small_size; i++) {
        std::pair tmp(a[i], b[i]);
        out.push_back(std::move(tmp));
    }
    return out;
}


int main(int argc, char* argv[])
{
    std::vector<int> a = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> b = { 1, 1, 3, 5, 8, 13, 21 };

    for (auto p : zip(a, b)) 
        std::cout << p.first << p.second << "\n";    
    return 0;
}
