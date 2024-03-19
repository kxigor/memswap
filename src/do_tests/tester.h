#ifndef TESTER_H
#define TESTER_H

#include <assert.h>
#include <dirent.h>
#include <malloc.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#define PATH_MAX 4096

typedef uint8_t BYTE;

typedef struct Result
{
    size_t block_sze;
    double time     ;
} Result;


void start_testing(
    const char* tests_in_dir , 
    const char* tests_out_dir, 
    void (*swap_ptr)(
        const void*, 
        const void*, 
        size_t
    )
);

Result do_test(
    FILE*  in_file,
    FILE* out_file,
    void (*swap_ptr)(
        const void*, 
        const void*, 
        size_t
    )
);

#endif // !TESTER_H