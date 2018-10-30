#include <gsl/gsl>
#include <iostream>

/*
Minimum function with any number of arguments 
Write a function template that can take any number of arguments
and returns the minimum value of them all, using operator < for comparison. 
Write a variant of this function template that can be parameterized
with a binary comparison function to use instead of operator <.
*/

template <typename ... T>
auto op_min(T ... args) {
    return std::min({args...});
}


int main(int argc, char* argv[]) {
    auto int_min = op_min(3, 2, 5, 7);
    std::cout << "int_min : " << int_min << "\n";
    double d_min = op_min(3.2, 1.4, 0.8, 5.9);
    printf("double min : %lf\n", d_min);
    return 0;
}
