#include <stdio.h>
#include <time.h>

#include "src/do_tests/tester.h"
#include "src/memswap/memswap.h"

int main(void)
{
    start_testing(
        "./src",
        "out",
        memswap_xor64
    );
}