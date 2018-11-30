#include <gsl/gsl>
#include <vector>
#include <string>


//Transforming a list of phone numbers
auto transform(std::vector<std::string> const&vec, int region) {
    std::string region_str = "+" + std::string(region);
    std::vector<std::string> out;
    for (auto num : vec) {
        num.erase(std::remove(num.begin(), num.end(), ' '), num.end());

        int start = (num[0] == "0" || num[0] == "+") ? 1 : 0;
        std::string new_num = region_str + num.substr(start);
        out.push_back(std::move(new_num));
    }
    return out;
}


int main(int argc, char* argv[]) {
    std::vector<std::string> vec = {
        "07555 123456",
        "07555123456",
        "+44 7555 123456",
        "44 7555 123456",
        "7555 123456",
    };

    for (auto n : transform(vec, 44)) 
        std::cout << n << std::endl;    
    return 0;
}
