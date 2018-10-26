#include <iostream>
#include <iterator>
#include <string>
#include <boost/tokenizer.hpp>
#include <typeinfo>

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

IPv4& IPv4::operator++() {
    bool carry = true;
    for (uint32_t idx = 3; idx >= 0 && carry ; idx--) {
        if (this->addr[idx] == 255) {
            this->addr[idx] = 0;
            carry = true;
        }
        else {
            this->addr[idx] += 1;
            carry = false;
        }
    }
    return *this;
}

IPv4 IPv4::operator++(int) {
    IPv4 tmp = *this;
    ++*this;
    return tmp;
}

bool IPv4::operator>(const IPv4 &a) {
    for (uint32_t idx = 0 ; idx < 4 ; idx++) {
        if (this->addr[idx] > a.addr[idx])
            return true;
        else if (this->addr[idx] < a.addr[idx])
            return false;
    }
    return false;
}

bool IPv4::operator<(const IPv4 &a) {
    return !(*this > a) && !(*this == a);
}

bool IPv4::operator==(const IPv4 &a) {
    return std::equal(std::begin(this->addr),
                      std::end(this->addr),
                      std::begin(a.addr));
}