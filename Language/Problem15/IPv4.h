#include <iostream>
#include <string>


class IPv4 {
    private:
        bool saved;
        uint8_t addr[4];
        bool strToV4(std::string &in_);
    public:
        void readFromConsole();
        void writeToConsole();
};