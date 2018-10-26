#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include "IPv4.h"


bool IPv4::strToV4(std::string &in_) {
    std::string num;
    boost::char_separator<char> seq(".");
    boost::tokenizer<boost::char_separator<char>> tokens(in_, seq);

    uint32_t i = 0;
    for (const auto &t : tokens) {
        bool isDigit = (t.find_first_not_of("0123456789") == std::string::npos);        
        if (!isDigit || i > 3 || t.length() > 3 || t.length() == 0)
            return false;
        this->addr[i++] = u_int8_t(std::stoi(t));
    }

    if (i != 4)
        return false;

    return true;
}

void IPv4::readFromConsole() {
    std::string in_;
    std::cin >> in_;
    
    this->saved = strToV4(in_);
    if (!this->saved)
        printf("Incorrect Format on Input\n");
}

void IPv4::writeToConsole() {
    if (this->saved)
        printf("%d.%d.%d.%d\n", this->addr[0], this->addr[1], this->addr[2], this->addr[3]);
}