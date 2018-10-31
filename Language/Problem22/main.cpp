#include <gsl/gsl>
#include <iostream>
#include <string>
/*
Literals of various temperature scales
Write a small library that enables expressing 
temperatures in the three most used scales, Celsius, Fahrenheit,
and Kelvin, and converting between them. 
The library must enable you to write temperature literals
in all these scales, such as 36.5_deg for Celsius, 97.7_f for Fahrenheit,
and 309.65_K for Kelvin; perform operations with these values; and convert between them.
*/

class Temperature {
    private:
        double cel, fah, kel;
    public:
        Temperature(std::string& input) {
            size_t token = input.find("_");
            double x = stod(input.substr(0, token));
            const char type = input[token + 1];

            if (type == 'd') {
                cel = x;
                fah = (x * 9/5) + 32;
                kel = x + 273.15;
            }
            else if (type == 'f') {
                fah = x;
                cel = (x - 32) * (5/9);
                kel = cel + 273.15;
            }
            else if (type == 'K') {
                kel = x;                
                cel = x - 273.15;
                fah = (cel * 9/5) + 32;
            }
        }

        void printout() {
            printf("cel : %lf, fah : %lf, kel : %lf\n", cel, fah, kel);
        }

};

int main(int argc, char* argv[])
{
    std::string input;
    std::cin >> input;
    Temperature t(input);
    t.printout();
    return 0;
}
