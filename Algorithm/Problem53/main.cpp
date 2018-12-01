#include <gsl/gsl>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>


// Average rating of movies
auto get_avg_rate(std::vector<int> const& vec) {
    std::sort(vec.begin(), vec.end());
    int start = vec.size() * 0.05;
    int end = vec.size() * 0.95;
    // start end 왜 안했지...
    return double(std::accumulate(vec.begin(), vec.end(), 0.0)) / double(end - start);
}

int main(int argc, char* argv[])
{
    std::vector<int> vec = {1,3,2,4,4,9,5,6,6,3,9,6,8,6};
    std::cout << get_avg_rate(vec) << "\n";
    return 0;
}
