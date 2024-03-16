#include <stdio.h>
#include <time.h>

#include "src/memswap.h"



int main(void)
{
    int64_t arr1[] = {1, 10, 100, 1000, 10000};
    int64_t arr2[] = {20000, 2000, 200, 20, 2};

    memswap_xor64(arr1, arr2, 16);
    for(size_t pos = 0; pos < sizeof(arr1) / sizeof(*arr1); pos++)
    {
        printf("%ld ", arr1[pos]);
    }
    putchar('\n');
    for(size_t pos = 0; pos < sizeof(arr2) / sizeof(*arr2); pos++)
    {
        printf("%ld ", arr2[pos]);
    }
    putchar('\n');
}