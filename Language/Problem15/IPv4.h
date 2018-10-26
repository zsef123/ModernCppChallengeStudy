#include <iostream>
#include <string>


class IPv4 {
    private:
        bool saved;
        uint32_t addr[4];
        bool strToV4(std::string &in_);

    public:
        void readFromConsole();
        void writeToConsole();

        IPv4& operator++();
        IPv4 operator++(int);
        bool operator>(const IPv4 &a);
        bool operator<(const IPv4 &a);
        bool operator==(const IPv4 &a);
};