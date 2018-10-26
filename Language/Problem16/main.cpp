#include <gsl/gsl>
#include "../Problem15/IPv4.cpp"

/*
Enumerating IPv4 addresses in a range 
Write a program that allows the user to input two IPv4 addresses 
representing a range and list all the addresses in that range.
Extend the structure defined for the previous problem to implement the requested functionality.
*/

void test_incremental(IPv4 x) {
    printf("###############\n");
    printf("Increment test\n");
    printf("x : "); x.writeToConsole();
    printf("x++ : "); (x++).writeToConsole();
    printf("++x : "); (++x).writeToConsole();
    printf("###############\n");
}

void test_compare(IPv4 a, IPv4 b) {
    ++b;
    printf("Compare Test\n");
    printf("a : "); a.writeToConsole();
    printf("b : "); b.writeToConsole();
    printf("(a > b) : %d, (a < b) : %d", (a > b), (a < b));
}

int main(int argc, char* argv[])
{
    IPv4 ip_big, ip_small;
    printf("1st input : "); ip_big.readFromConsole();  
    printf("2nd input : "); ip_small.readFromConsole();  

    if (ip_small > ip_big) {
        IPv4 tmp = ip_small;
        ip_small = ip_big;
        ip_big = tmp;
    }

    while (ip_small < ip_big)
        (++ip_small).writeToConsole();
    return 0;
}
