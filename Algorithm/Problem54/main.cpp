#include <gsl/gsl>
#include <pair>
#include <iostream>
#include <vector>

// Pairwise algorithm
auto to_pair(std::vector<int> const& vec) {
    std::vector<std::pair> out;
    int end = vec.size() / 2;
    for (int i = 0 ; i < end; i+=2) {
        std::pair tmp(vec[i], vec[i+1]);
        out.push_back(std::move(tmp));
    }
    return out;
}

int main(int argc, char* argv[])
{
    std::vector<int> vec = {1, 1, 3, 5, 8, 13, 21};
    for (auto p : to_pair(vec)) 
        std::cout << p.first() << p.second() << "\n";    
    return 0;
}
