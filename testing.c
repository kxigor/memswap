#include "src/do_tests/tester.h"
#include "src/memswap/memswap.h"
#include "src/graphs_generator/gen_graph.h"

void test_1();
void test_2();
void test_3();

int main(void)
{

    test_1();
    test_2();
    test_3();
}

void test_1()
{
    start_testing(
        "./tests/big_tests",
        "./result/1",
        "memswap_xor64",
        memswap_xor64
    );

    start_testing(
        "./tests/big_tests",
        "./result/1",
        "memswap_xor32",
        memswap_xor32
    );

    start_testing(
        "./tests/big_tests",
        "./result/1",
        "memswap_xor08",
        memswap_xor8
    );

    start_testing(
        "./tests/big_tests",
        "./result/1",
        "memswap_tmp64",
        memswap_tmp64
    );

    start_testing(
        "./tests/big_tests",
        "./result/1",
        "memswap_tmp32",
        memswap_tmp32
    );

    start_testing(
        "./tests/big_tests",
        "./result/1",
        "memswap_tmp08",
        memswap_tmp8
    );

    start_testing(
        "./tests/big_tests",
        "./result/1",
        "memswap_add64",
        memswap_add64
    );

    start_testing(
        "./tests/big_tests",
        "./result/1",
        "memswap_add32",
        memswap_add32
    );

    start_testing(
        "./tests/big_tests",
        "./result/1",
        "memswap_add08",
        memswap_add8
    );

    ScriptGraph(
        "./result/1",
        "./graphs/test1.png",
        "./src/graphs_generator/Footage.py"
    );
}

void test_2()
{
    start_testing(
        "./tests/big_lot_same",
        "./result/2",
        "memswap_xor64",
        memswap_xor64
    );

    start_testing(
        "./tests/big_lot_same",
        "./result/2",
        "memswap_xor32",
        memswap_xor32
    );

    start_testing(
        "./tests/big_lot_same",
        "./result/2",
        "memswap_xor08",
        memswap_xor8
    );

    start_testing(
        "./tests/big_lot_same",
        "./result/2",
        "memswap_tmp64",
        memswap_tmp64
    );

    start_testing(
        "./tests/big_lot_same",
        "./result/2",
        "memswap_tmp32",
        memswap_tmp32
    );

    start_testing(
        "./tests/big_lot_same",
        "./result/2",
        "memswap_tmp08",
        memswap_tmp8
    );

    start_testing(
        "./tests/big_lot_same",
        "./result/2",
        "memswap_add64",
        memswap_add64
    );

    start_testing(
        "./tests/big_lot_same",
        "./result/2",
        "memswap_add32",
        memswap_add32
    );

    start_testing(
        "./tests/big_lot_same",
        "./result/2",
        "memswap_add08",
        memswap_add8
    );

    ScriptGraph(
        "./result/2",
        "./graphs/test2.png",
        "./src/graphs_generator/Footage.py"
    );
}

void test_3()
{
    start_testing(
        "./tests/very_small_tests",
        "./result/3",
        "memswap_xor64",
        memswap_xor64
    );

    start_testing(
        "./tests/very_small_tests",
        "./result/3",
        "memswap_xor32",
        memswap_xor32
    );

    start_testing(
        "./tests/very_small_tests",
        "./result/3",
        "memswap_xor08",
        memswap_xor8
    );

    start_testing(
        "./tests/very_small_tests",
        "./result/3",
        "memswap_tmp64",
        memswap_tmp64
    );

    start_testing(
        "./tests/very_small_tests",
        "./result/3",
        "memswap_tmp32",
        memswap_tmp32
    );

    start_testing(
        "./tests/very_small_tests",
        "./result/3",
        "memswap_tmp08",
        memswap_tmp8
    );

    start_testing(
        "./tests/very_small_tests",
        "./result/3",
        "memswap_add64",
        memswap_add64
    );

    start_testing(
        "./tests/very_small_tests",
        "./result/3",
        "memswap_add32",
        memswap_add32
    );

    start_testing(
        "./tests/very_small_tests",
        "./result/3",
        "memswap_add08",
        memswap_add8
    );

    ScriptGraph(
        "./result/3",
        "./graphs/test3.png",
        "./src/graphs_generator/Footage.py"
    );
}