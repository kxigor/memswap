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
    void (*swap_testing)(
        const void*, 
        const void*, 
        size_t
    )
)
{
    assert(tests_in_dir  != NULL);
    assert(tests_out_dir != NULL);
    assert(swap_testing  != NULL);

    DIR* dir = opendir(tests_in_dir);
    assert(dir != NULL);

    /*The full path to the file*/
    char            file_pwd[PATH_MAX] = {};
    /*the object from the dictory*/
    struct dirent*  file_object = NULL;
    /*We get information about the object that we considered*/
    struct stat     file_stat = {};

    while ((file_object = readdir(dir)) != NULL)
    {
        sprintf(
            file_pwd    ,
            "%s/%s"     ,
            tests_in_dir, 
            file_object->d_name
        );

        int stat_status = stat(file_pwd, &file_stat);

        /*there is no access to the file*/
        assert(stat_status == 0);

        if(S_ISDIR(file_stat.st_mode))
        {
            /*We were counting the folder*/
            continue;
        }

        printf("FILENAME: %s\n", file_pwd);
    }

    closedir(dir);
}

Result do_test(
    FILE*  in_file,
    FILE* out_file,
    void (*swap_testing)(
        const void*, 
        const void*, 
        size_t
    )
)
{
    assert( in_file     != NULL);
    assert(out_file     != NULL);
    assert(swap_testing != NULL);

    /*Getting the file size*/
    fseek(in_file, 0, SEEK_END);
    long in_file_size = ftell(in_file);
    fseek(in_file, 0, SEEK_SET);

    BYTE* buffer = calloc(in_file_size, sizeof(BYTE));
    assert(buffer != NULL);

    int fread_status = 0;
    fread_status = fread(buffer, sizeof(BYTE), in_file_size, in_file);

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
    BYTE* s_block_testing = result_buffer; + block_sze;

    swap_testing()
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