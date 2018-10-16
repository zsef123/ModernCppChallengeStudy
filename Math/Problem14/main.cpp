#include <gsl/gsl>

// Write a program that validates that 10-digit values entered by the user, as a string, represent valid ISBN-10 numbers.

bool validISBN(char *isbn) {
    int sum = 0;
    for (int i = 0; i < 10; i++) 
        sum += int(isbn[i] - '0')  * (i + 1);
    return sum % 11;
}

int main(int argc, char* argv[])
{
    char input[11] = {0};
    printf("Input string : "); scanf("%s", input);

    bool flag = validISBN(input);
    if (flag)
        printf("ISBN True");
    else
        printf("ISBN False");
    return 0;
}
