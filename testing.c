#include <stdio.h>
#include <time.h>

#include "src/do_tests/tester.h"
#include "src/memswap/memswap.h"
#include "src/graphs_generator/gen_graph.h"
int main(void)
{
    
    start_testing(
        "./tests/big_tests",
        "./result/2",
        "memswap_xor64",
        memswap_xor64
    );

    start_testing(
        "./tests/big_tests",
        "./result/2",
        "memswap_xor32",
        memswap_xor32
    );

    start_testing(
        "./tests/big_tests",
        "./result/2",
        "memswap_xor08",
        memswap_xor8
    );

    start_testing(
        "./tests/big_tests",
        "./result/2",
        "memswap_tmp64",
        memswap_tmp64
    );

    start_testing(
        "./tests/big_tests",
        "./result/2",
        "memswap_tmp32",
        memswap_tmp32
    );

    start_testing(
        "./tests/big_tests",
        "./result/2",
        "memswap_tmp08",
        memswap_tmp8
    );
    

    ScriptGraphCreate(
        "./result/2"    ,
        "./graphs"   ,
        "test1.png"   ,
        "./src/graphs_generator",
        "Footage.py"
    );
}