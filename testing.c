#include <stdio.h>
#include <time.h>

#include "src/do_tests/tester.h"
#include "src/memswap/memswap.h"

int main(void)
{
    start_testing(
        "./tests/tests",
        "./result" ,
        "memswap_xor64",
        memswap_xor64
    );
}