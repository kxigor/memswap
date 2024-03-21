#include "tester.h"

/*
    working_swap
    To convince you of the 
    correctness of the algorithm
*/
void __memswap_tmp8(void* a, void* b, size_t sze);

void start_testing(
    const char* tests_in_dir , 
    const char* tests_out_dir,
    const char* swap_name    ,
    void (*swap_testing)(
        void*, 
        void*, 
        size_t
    )
)
{
    assert(tests_in_dir  != NULL);
    assert(tests_out_dir != NULL);
    assert(swap_name     != NULL);
    assert(swap_testing  != NULL);

    /*
        The specified folder 
        does not necessarily exist
    */
    DirInit(tests_out_dir);

    /*
        Open the output file, 
        all the results will be written to it
    */
    char output_file_pwd[PATH_MAX] = {};
    sprintf(
        output_file_pwd ,
        "%s/%s.out"     ,
        tests_out_dir   ,
        swap_name
    );
    FILE* output_file = fopen(output_file_pwd, "w");
    assert(output_file != NULL);
    /*
        At the beginning of the file 
        is the name of the function
    */
    fprintf(output_file, "%s\n", swap_name);

    Dir* input_dir = DirCtor(tests_in_dir);
    char* input_file_name = NULL;

    while ((input_file_name = DirGetNextFileName(input_dir)) != NULL)
    {
        FILE* input_file = fopen(input_file_name, "rb");
        assert(input_file != NULL);

        do_test(
            input_file  ,
            output_file ,
            swap_testing
        );

        fclose(input_file);
        free(input_file_name);
    }

    fclose(output_file);
    DirDtor(input_dir);
}

void do_test(
    FILE*  in_file,
    FILE* out_file,
    void (*swap_testing)(
        void*, 
        void*, 
        size_t
    )
)
{
    assert( in_file     != NULL);
    assert(out_file     != NULL);
    assert(swap_testing != NULL);

    /*Getting the file size*/
    fseek(in_file, 0, SEEK_END);
    size_t in_file_size = (size_t)ftell(in_file);
    fseek(in_file, 0, SEEK_SET);

    BYTE* buffer = calloc(in_file_size, sizeof(BYTE));
    assert(buffer != NULL);

    size_t fread_status = 0;
    fread_status = fread(
        buffer      , 
        sizeof(BYTE), 
        in_file_size, 
        in_file
    );

    assert(fread_status == in_file_size * sizeof(BYTE));

    /*
        The file consists of two blocks that need to be swapped, 
        they are the same size, so it should be divided by 2
    */
    assert(in_file_size % 2 == 0);
    size_t block_sze = in_file_size / 2;

    BYTE* result_buffer = calloc(in_file_size, sizeof(BYTE));
    assert(result_buffer != NULL);

    memcpy(result_buffer, buffer, in_file_size * sizeof(BYTE));

    BYTE* f_block_stable  = buffer;
    BYTE* s_block_stable  = buffer + block_sze;

    BYTE* f_block_testing = result_buffer;
    BYTE* s_block_testing = result_buffer + block_sze;

    clock_t start = clock();
    swap_testing(
        f_block_testing,
        s_block_testing,
        block_sze
    );
    clock_t stop  = clock();

    /*
        Checking the correctness 
        of the swap function
    */
    __memswap_tmp8(
        f_block_stable,
        s_block_stable,
        block_sze
    );

    assert(
        strncmp(
            (char*)buffer       , 
            (char*)result_buffer, 
            in_file_size
        ) == 0
    );

    fprintf(
        out_file    ,
        "%zu %f\n"  ,
        block_sze   ,
        (double)(stop - start) / (double)CLOCKS_PER_SEC
    );

    free(result_buffer);
    free(buffer);
}

void __memswap_tmp8(void* a, void* b, size_t sze)
{
    int8_t* ptr_8_a = (int8_t*)a;
    int8_t* ptr_8_b = (int8_t*)b;

    int8_t temp_8 = 0;

    while (sze > 0)
    {
        temp_8     = *ptr_8_a ;
        *ptr_8_a   = *ptr_8_b ;
        *ptr_8_b   = temp_8   ;

        sze -= 1UL            ;
        ptr_8_a++, ptr_8_b++  ;
    }
}