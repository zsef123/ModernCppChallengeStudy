#include <gsl/gsl>
#include <iostream>
#include <string>
#include "IPv4.cpp"
/*
IPv4 data type Write a class that represents an IPv4 address.
Implement the functions required to be able to read and write such addresses from or to the console.
The user should be able to input values in dotted form, such as 127.0.0.1 or 168.192.0.100.
This is also the form in which IPv4 addresses should be formatted to an output stream
*/


int main(int argc, char* argv[])
{
    IPv4 ipv4;
    ipv4.readFromConsole();
    ipv4.writeToConsole();

    return 0;
}
