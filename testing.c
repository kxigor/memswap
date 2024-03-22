#include "src/do_tests/tester.h"
#include "src/memswap/memswap.h"
#include "src/graphs_generator/gen_graph.h"

#define test_all(number, test_dir)              \
    do                                          \
    {                                           \
        start_testing(                          \
            test_dir,                           \
            "./result/" #number,                \
            "memswap_xor64",                    \
            memswap_xor64                       \
        );                                      \
                                                \
        start_testing(                          \
            test_dir,                           \
            "./result/" #number,                \
            "memswap_xor32",                    \
            memswap_xor32                       \
        );                                      \
                                                \
        start_testing(                          \
            test_dir,                           \
            "./result/" #number,                \
            "memswap_xor08",                    \
            memswap_xor8                        \
        );                                      \
                                                \
        start_testing(                          \
            test_dir,                           \
            "./result/" #number,                \
            "memswap_tmp64",                    \
            memswap_tmp64                       \
        );                                      \
                                                \
        start_testing(                          \
            test_dir,                           \
            "./result/" #number,                \
            "memswap_tmp32",                    \
            memswap_tmp32                       \
        );                                      \
                                                \
        start_testing(                          \
            test_dir,                           \
            "./result/" #number,                \
            "memswap_tmp08",                    \
            memswap_tmp8                        \
        );                                      \
                                                \
        start_testing(                          \
            test_dir,                           \
            "./result/" #number,                \
            "memswap_add64",                    \
            memswap_add64                       \
        );                                      \
                                                \
        start_testing(                          \
            test_dir,                           \
            "./result/" #number,                \
            "memswap_add32",                    \
            memswap_add32                       \
        );                                      \
                                                \
        start_testing(                          \
            test_dir,                           \
            "./result/" #number,                \
            "memswap_add08",                    \
            memswap_add8                        \
        );                                      \
                                                \
        ScriptGraph(                            \
            "./result/" #number,                \
            "./graphs/test"#number".png",       \
            "./src/graphs_generator/Footage.py" \
        );                                      \
    } while (0);

int main(void)
{
//------------------------------ Sector 1, without flags
    /*
    test_all(1, "./tests/big_tests");
    test_all(2, "./tests/big_lot_same");
    test_all(3, "./tests/very_small_tests");
    */
//------------------------------ Sector 2, with -O3
    /*
    test_all(4, "./tests/big_tests");
    test_all(5, "./tests/big_lot_same");
    test_all(6, "./tests/very_small_tests");
    */
//------------------------------ Sector 3, with numerous flags
    
    test_all(7, "./tests/big_tests");
    test_all(8, "./tests/big_lot_same");
    test_all(9, "./tests/very_small_tests");
    
}