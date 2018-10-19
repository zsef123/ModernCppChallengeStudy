#include <gsl/gsl>
#include <bitset>
#include <string>
#define uint uint32_t

auto binToGray(std::bitset<5> &bin) {
    std::bitset<5> gray(0);
    gray[4] = bin[4];

    for (int i = 4; i > 0; i--)
        gray[i - 1] = bin[i] ^ bin[i - 1];
        
    return gray;
}
auto grayToBin(std::bitset<5> &gray) {
    std::bitset<5> bin(0);
    bin[4] = gray[4];

    for (int i = 4; i > 0; i--)
        bin[i - 1] = bin[i] ^ gray[i - 1];

    return bin;
}

int main(int argc, char* argv[])
{
    uint x;
    printf("input :"); scanf("%d", &x);

    std::bitset<5> bin(x);
    printf("bin : %s\n", bin.to_string().c_str());

    auto gray = binToGray(bin);
    printf("gray : %s\n", gray.to_string().c_str());

    auto bin2 = grayToBin(gray);
    printf("bin2 : %s\n", bin2.to_string().c_str());

    return 0;
}
