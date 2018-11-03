#include <gsl/gsl>
#include <iostream>
#include <vector>

/*
Adding a range of values to a container 
Write a general-purpose function that can add any number of elements
to the end of a container that has a method push_back(T&& value).
*/

// https://github.com/revsic/ModernCppChallengeStudy/blob/master/Language/Problem19/main.cpp
template <typename C, typename ... T>
void push_back(C& c, T&&... items) {
    // why use forward?
    // L, R value를 나눠서 넘겨준다.
    // (container.push_back(std::forward<T>(items)), ...);
    (c.push_back(items), ...);
}

int main(int argc, char* argv[])
{
    std::vector<int> v = { 1, 2 };
    push_back(v, 3, 4, 5);

    for (int i : v)
        std::cout << i << std::endl;
    return 0;
}
