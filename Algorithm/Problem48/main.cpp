#include <gsl/gsl>
#include <vector>
#include <unordered_map>
#include <iostream>

template <typename T>
auto get_frequent_elem(std::vector<T> vec) {
    std::unordered_map<T, int> map;
    for (T v : vec)
        map[v]++;

    std::vector<std::pair<T, int>> cnt(map.begin(), map.end());
    auto cmp = [](std::pair<T, int> a, std::pair<T, int> b) { return a.second > b.second; };    
    std::sort(cnt.begin(), cnt.end(), cmp);
    return cnt;
}

int main(int argc, char* argv[]) {
    std::vector<int> vec = {1,1,3,5,8,13,3,5,8,8,5};
    int max = 0;
    for (auto const& i : get_frequent_elem(vec)) {
        if (max != 0 && max != i.second)
            break;
        else if (max == 0)
            max = i.second;
        
        std::cout << i.first << " : " << i.second << "\n";        
    }
    return 0;
}
