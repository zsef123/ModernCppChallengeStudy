#include <gsl/gsl>
#include <vector>
#include <string>
#include <algorithm>


// Generating all the permutations of a string
int main(int argc, char* argv[]) {
    std::string s="abcd";
    std::sort(s.begin(), s.end());
    do {
        std::cout << s << std::endl;
    } while(std::next_permutation(s.begin(),s.end()));
    return 0;
}
