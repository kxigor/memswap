#include <stdlib.h>

#include <assert.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include "../dirs/dirs.h"

#define PATH_MAX 4096

typedef uint8_t BYTE;

typedef struct Request
{
    size_t from         ;
    size_t to           ;
    size_t step         ;
    size_t repetitions  ;

    char* tests_dir     ;

    uint8_t min_val     ;
    uint8_t max_val     ;
} Request;

void RequestReceive(Request* req);
bool RequestExecute(Request* req);
void RequestClear  (Request* req);

BYTE gen_rand_byte(BYTE min, BYTE max);

int main(void)
{
    srand(time(NULL));

    bool ex_st = false;

    Request req = {};
    RequestReceive  (&req);
    ex_st = 
    RequestExecute  (&req);
    assert(ex_st);
    printf("The request was completed successfully!");
    RequestClear    (&req);
}

void RequestReceive(Request* req)
{
    assert(req != NULL);
    
    printf("Enter the starting block size (from) : ");
    scanf("%zu", &req->from);

    printf("Enter the final block size (to) : ");
    scanf("%zu", &req->to);

    printf("Enter the step (step) : ");
    scanf("%zu", &req->step);

    printf("Enter the number of repetitions of the same size (repetitions) : ");
    scanf("%zu", &req->repetitions);

    req->tests_dir = calloc(PATH_MAX, sizeof(uint8_t));
    assert(req->tests_dir != NULL);

    printf("Enter the output folder (tests_dir) : ");
    scanf("%s", req->tests_dir);

    printf("Enter the minimum byte value 0-255 (min_val) : ");
    scanf("%hhu", &req->min_val);

    printf("Enter the maximum byte value 0-255 (max_val) : ");
    scanf("%hhu", &req->max_val);
}

bool RequestExecute(Request* req)
{
    assert(req != NULL);
    assert(req->tests_dir != NULL);

    char filename[PATH_MAX] = {};

    /*
        Multiply by 2 because we work with two memory sections
    */
    BYTE* buf = calloc(req->to * 2, sizeof(BYTE));
    assert(buf != NULL);

    DirInit(req->tests_dir);

    for(size_t pos = req->from; pos <= req->to; pos += req->step)
    {
        for(size_t k = 0; k < req->repetitions; k++)
        {
            sprintf(
                filename        ,
                "%s/%zu_%zu.in" ,
                req->tests_dir  ,
                pos             ,
                k
            );

            FILE* outfile = fopen(filename, "wb");
            assert(outfile != NULL);

            /*
                Multiply by 2 because we work with two memory sections
            */
            for(size_t byte_pos = 0; byte_pos < pos * 2; byte_pos++)
            {
                buf[byte_pos] = gen_rand_byte(
                    req->min_val, 
                    req->max_val
                );
            }

            fwrite(buf, sizeof(BYTE), pos * 2, outfile);

            fclose(outfile);
        }
    }
}

void RequestClear(Request* req)
{
    assert(req != NULL);
    assert(req->tests_dir != NULL);
    free(req->tests_dir);
}

BYTE gen_rand_byte(BYTE min, BYTE max)
{
    if(min >= max)
    {
        return min;
    }
    return min + rand() % (max - min);
}