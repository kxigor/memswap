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
#include <time.h>
#define PATH_MAX 4096

typedef uint8_t BYTE;

void start_testing(
    const char* tests_in_dir , 
    const char* tests_out_dir,
    const char* swap_name    ,
    void (*swap_testing)(
        void*, 
        void*, 
        size_t
    )
);

void do_test(
    FILE*  in_file,
    FILE* out_file,
    void (*swap_testing)(
        void*, 
        void*, 
        size_t
    )
);

#endif // !TESTER_H