#include "memswap.h"

void memswap_xor64(void* a, void* b, size_t sze)
{
    int64_t* ptr_64_a = (int64_t*)a;
    int64_t* ptr_64_b = (int64_t*)b;

    for (; sze >= SZE64; sze -= SZE64, ptr_64_a++, ptr_64_b++)
    {
        if(*ptr_64_a == *ptr_64_b)
        {
            continue;
        }
        *ptr_64_a ^= *ptr_64_b;
        *ptr_64_b ^= *ptr_64_a;
        *ptr_64_a ^= *ptr_64_b;
    }

    int8_t* ptr_8_a = (int8_t*)ptr_64_a;
    int8_t* ptr_8_b = (int8_t*)ptr_64_b;

    for (; sze > 0; sze -= SZE8, ptr_8_a++, ptr_8_b++)
    {
        if(*ptr_8_a == *ptr_8_b)
        {
            continue;
        }
        *ptr_8_a ^= *ptr_8_b;
        *ptr_8_b ^= *ptr_8_a;
        *ptr_8_a ^= *ptr_8_b;
    }
}

void memswap_xor32(void* a, void* b, size_t sze)
{
    int32_t* ptr_32_a = (int32_t*)a;
    int32_t* ptr_32_b = (int32_t*)b;

    for (; sze >= SZE32; sze -= SZE32, ptr_32_a++, ptr_32_b++)
    {
        if(*ptr_32_a == *ptr_32_b)
        {
            continue;
        }
        *ptr_32_a ^= *ptr_32_b;
        *ptr_32_b ^= *ptr_32_a;
        *ptr_32_a ^= *ptr_32_b;
    }

    int8_t* ptr_8_a = (int8_t*)ptr_32_a;
    int8_t* ptr_8_b = (int8_t*)ptr_32_b;

    for (; sze > 0; sze -= SZE8, ptr_8_a++, ptr_8_b++)
    {
        if(*ptr_8_a == *ptr_8_b)
        {
            continue;
        }
        *ptr_8_a ^= *ptr_8_b;
        *ptr_8_b ^= *ptr_8_a;
        *ptr_8_a ^= *ptr_8_b;
    }
}

void memswap_tmp64(void* a, void* b, size_t sze)
{
    int64_t* ptr_64_a = (int64_t*)a;
    int64_t* ptr_64_b = (int64_t*)b;

    int64_t temp_64 = 0;

    while (sze >= SZE64)
    {
        temp_64     = *ptr_64_a ;
        *ptr_64_a   = *ptr_64_b ;
        *ptr_64_b   = temp_64   ;

        sze -= SZE64;
        ptr_64_a++, ptr_64_b++  ;
    }

    int8_t* ptr_8_a = (int8_t*)ptr_64_a;
    int8_t* ptr_8_b = (int8_t*)ptr_64_b;

    int8_t temp_8 = 0;

    while (sze > 0)
    {
        temp_8     = *ptr_8_a ;
        *ptr_8_a   = *ptr_8_b ;
        *ptr_8_b   = temp_8   ;
        
        sze -= SZE8;
        ptr_8_a++, ptr_8_b++  ;
    }
}

void memswap_tmp32(void* a, void* b, size_t sze)
{
    int32_t* ptr_32_a = (int32_t*)a;
    int32_t* ptr_32_b = (int32_t*)b;

    int32_t temp_32 = 0;

    while (sze >= SZE32)
    {
        temp_32     = *ptr_32_a ;
        *ptr_32_a   = *ptr_32_b ;
        *ptr_32_b   = temp_32   ;

        sze -= SZE32;
        ptr_32_a++, ptr_32_b++  ;
    }

    int8_t* ptr_8_a = (int8_t*)ptr_32_a;
    int8_t* ptr_8_b = (int8_t*)ptr_32_b;

    int8_t temp_8 = 0;

    while (sze > 0)
    {
        temp_8     = *ptr_8_a ;
        *ptr_8_a   = *ptr_8_b ;
        *ptr_8_b   = temp_8   ;

        sze -= SZE8;
        ptr_8_a++, ptr_8_b++  ;
    }
}

void memswap_xor8(void* a, void* b, size_t sze)
{
    int8_t* ptr_8_a = (int8_t*)a;
    int8_t* ptr_8_b = (int8_t*)b;

    for (; sze > 0; sze -= SZE8, ptr_8_a++, ptr_8_b++)
    {
        if(*ptr_8_a == *ptr_8_b)
        {
            continue;
        }
        *ptr_8_a ^= *ptr_8_b;
        *ptr_8_b ^= *ptr_8_a;
        *ptr_8_a ^= *ptr_8_b;
    }
}

void memswap_tmp8(void* a, void* b, size_t sze)
{
    int8_t* ptr_8_a = (int8_t*)a;
    int8_t* ptr_8_b = (int8_t*)b;

    int8_t temp_8 = 0;

    while (sze > 0)
    {
        temp_8     = *ptr_8_a ;
        *ptr_8_a   = *ptr_8_b ;
        *ptr_8_b   = temp_8   ;

        sze -= SZE8;
        ptr_8_a++, ptr_8_b++  ;
    }
}