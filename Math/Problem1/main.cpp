#include <gsl/gsl>
#include <math.h>
/*
* Write a program that calculates and prints
* the sum of all the natural numbers divisible by either 3 or 5,
* up to a given limit entered by the user.
*/

unsigned int div3or5(int input_) {
    if (input_ == 3)
        return 3;
    /*
    unsigned int output_ = 0;
    for (unsigned int i = 0; i <= input_ ; i += 3)
        output_ += i;
    for (unsigned int i = 0; i <= input_ ; i += 5) 
        output_ += i;
    for (unsigned int i = 0; i <= input_ ; i += 15) 
        output_ -= i;
    */
   
    uint32_t output_ = 0;
    output_ += 3 * pow(3, int(input_ / 3)) / 2;
    output_ += 5 * pow(5, int(input_ / 5)) / 4;
    output_ -= 15 * pow(15, int(input_ / 15)) / 14;
    return output_;
}

int main(int argc, char* argv[])
{   
    unsigned int input_;
    printf("Input Numer : "); scanf("%d", &input_);

    unsigned int output_ = div3or5(input_);
    printf("Sum : %d\n", output_);
    return 0;
}
