#include <iostream>
#include <regex>
#include <string>

// License plate validation

void print_license(const std::string &s) {
    std::regex r("[A-Z]{3}-[A-Z]{2} [0-9]{3}");
    for(std::sregex_iterator i = std::sregex_iterator(s.begin(), s.end(), r);
                             i != std::sregex_iterator();
                             ++i )
    {
        std::smatch m = *i;
        std::cout << m.str() << " at position " << m.position() << '\n';
    }
}

int main(int argc, char* argv[])
{
    std::string input = "AZA-FE 012, vsdvvz, ZVZ-ZZ 000";
    print_license(input);
    return 0;
}
