#include <gsl/gsl>
#include <iostream>
#include <list>
#include <vector>
/*
Container any, all, none
Write a set of general-purpose functions
that enable checking whether any, all, or none of
the specified arguments are present in a given container.
*/

template <typename C, typename ... T>
bool contains_all(C& c, T&& ... args) {
    return ((std::find(c.begin(), c.end(), args) != c.end()) && ...);
}

template <typename C, typename ... T>
bool contains_any(C& c, T&& ... args) {
    return ((std::find(c.begin(), c.end(), args) != c.end()) || ...);
}

template <typename C, typename ... T>
bool contains_none(C& c, T&& ... args) {
    return !((std::find(c.begin(), c.end(), args) == c.end()) || ...);
}

int main(int argc, char* argv[])
{
    // These functions should make it possible to write code as follows:
    std::array<int, 6> a{ { 1, 2, 3, 4, 5, 6 } };
    assert(contains_all(a, 1, 3, 5, 6));
    std::cout << "all_1357 : " << contains_all(a, 1, 3, 5 ,7) << "\n";

    std::vector<int> v{ 1, 2, 3, 4, 5, 6 };
    assert(contains_any(v, 0, 3, 30));
    std::cout << "any_89 : " << contains_all(a, 8, 9) << "\n";


    std::list<int> l{ 1, 2, 3, 4, 5, 6 };
    assert(!contains_none(l, 0, 6));
    std::cout << "none_98 : " << contains_all(a, 9, 8) << "\n";
    return 0;
}
