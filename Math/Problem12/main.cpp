#include <gsl/gsl>

// Write a program that determines and prints which number up to 1 million produces the longest Collatz sequence and what its length is.

uint32_t getLongestSeq(uint32_t x) {
    uint32_t longestLen = 1;
    for (uint32_t i = 2; i <= x ; i++) {
        uint32_t len = 1;
        uint64_t seq = i;
        while (seq != 1) {
            if (seq % 2 == 0)
                seq /= 2;
            else
                seq = 3 * seq + 1;
            len++;
        }
        if (len > longestLen)
            longestLen = len;
    }
    return longestLen;
}
int main(int argc, char* argv[])
{
    uint32_t x;
    printf("input :"); scanf("%d", &x);

    uint32_t longestLengh = getLongestSeq(x);
    printf("%d\n", longestLengh);
    return 0;
}
