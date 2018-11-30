#include <gsl/gsl>
#include <iostream>
#include <vector>
#include <string>

// Filtering a list of phone numbers
// type const& == const type & ??
auto phone_filter(std::vector<std::string> const& vec, int region) {
    std::vector<std::string> filtered;
    for (auto const& num : vec) {
        int start = 0;
        if (num[0] == '+')
            start++;     

        std::string n = num.substr(start, 2);
        if (std::stoi(n) == region) {
            // what diff with push_back
            filtered.emplace_back(num);
        }
    }
    return filtered;
}

int main(int argc, char* argv[]) {
    std::vector<std::string> vec = {
        "+821012345678",
        "821012345678",
        "01012345678",
        "+82-10-1234-5678",
        "82-10-1234-4567",
        "010-1234-5678"
    };

    for (auto n : phone_filter(vec, 82)) 
        std::cout << n << std::endl;    
    return 0;
}
