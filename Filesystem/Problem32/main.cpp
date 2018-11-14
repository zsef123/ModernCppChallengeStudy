#include <gsl/gsl>
#include <iostream>
#include <vector>

// Pascal's Triangle

void vector_print(const std::vector<uint32_t>& vec, const int idx, const int maxidx) {
    for (int i = 0 ; i < (maxidx - idx); i++)
        std::cout << " " ;
    
    for (int i = 0 ; i < idx; i++) 
        std::cout << vec[i] << " ";
    std::cout << "\n";
}

void pascal(const int n) {
    std::vector<uint32_t> v1(n); v1[0] = 1;
    std::vector<uint32_t> v2(n); v2[0] = v2[1] = 1;

    vector_print(v1, 1, n + 1);
    vector_print(v2, 2, n + 1);

    std::vector<uint32_t> &rv = v1;
    std::vector<uint32_t> &lv = v2;
    for (int i = 3; i <= (n + 1); i++) {
        for (int j = 1; j < (i - 1) ; j++) 
            rv[j] = lv[j - 1] + lv[j];    
        rv[i - 1]  = 1;
        vector_print(rv, i, n + 1);
        std::swap(rv, lv);
    }
}


int main(int argc, char* argv[])
{
    pascal(10);
    return 0;
}
