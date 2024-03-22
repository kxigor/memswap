#include "memswap.h"

void memswap_xor64(void* a, void* b, size_t sze)
{
    uint64_t* ptr_64_a = (uint64_t*)a;
    uint64_t* ptr_64_b = (uint64_t*)b;

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

    uint8_t* ptr_8_a = (uint8_t*)ptr_64_a;
    uint8_t* ptr_8_b = (uint8_t*)ptr_64_b;

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
    uint32_t* ptr_32_a = (uint32_t*)a;
    uint32_t* ptr_32_b = (uint32_t*)b;

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

    uint8_t* ptr_8_a = (uint8_t*)ptr_32_a;
    uint8_t* ptr_8_b = (uint8_t*)ptr_32_b;

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

void memswap_xor8(void* a, void* b, size_t sze)
{
    uint8_t* ptr_8_a = (uint8_t*)a;
    uint8_t* ptr_8_b = (uint8_t*)b;

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
    uint64_t* ptr_64_a = (uint64_t*)a;
    uint64_t* ptr_64_b = (uint64_t*)b;

    uint64_t temp_64 = 0;

    while (sze >= SZE64)
    {
        temp_64     = *ptr_64_a ;
        *ptr_64_a   = *ptr_64_b ;
        *ptr_64_b   = temp_64   ;

        sze -= SZE64;
        ptr_64_a++, ptr_64_b++  ;
    }

    uint8_t* ptr_8_a = (uint8_t*)ptr_64_a;
    uint8_t* ptr_8_b = (uint8_t*)ptr_64_b;

    uint8_t temp_8 = 0;

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
    uint32_t* ptr_32_a = (uint32_t*)a;
    uint32_t* ptr_32_b = (uint32_t*)b;

    uint32_t temp_32 = 0;

    while (sze >= SZE32)
    {
        temp_32     = *ptr_32_a ;
        *ptr_32_a   = *ptr_32_b ;
        *ptr_32_b   = temp_32   ;

        sze -= SZE32;
        ptr_32_a++, ptr_32_b++  ;
    }

    uint8_t* ptr_8_a = (uint8_t*)ptr_32_a;
    uint8_t* ptr_8_b = (uint8_t*)ptr_32_b;

    uint8_t temp_8 = 0;

    while (sze > 0)
    {
        temp_8     = *ptr_8_a ;
        *ptr_8_a   = *ptr_8_b ;
        *ptr_8_b   = temp_8   ;

        sze -= SZE8;
        ptr_8_a++, ptr_8_b++  ;
    }
}

void memswap_tmp8(void* a, void* b, size_t sze)
{
    uint8_t* ptr_8_a = (uint8_t*)a;
    uint8_t* ptr_8_b = (uint8_t*)b;

    uint8_t temp_8 = 0;

    while (sze > 0)
    {
        temp_8     = *ptr_8_a ;
        *ptr_8_a   = *ptr_8_b ;
        *ptr_8_b   = temp_8   ;

        sze -= SZE8;
        ptr_8_a++, ptr_8_b++  ;
    }
}

void memswap_add64(void* a, void* b, size_t sze)
{
    uint64_t* ptr_64_a = (uint64_t*)a;
    uint64_t* ptr_64_b = (uint64_t*)b;

    while (sze >= SZE64)
    {
        *ptr_64_a = *ptr_64_a + *ptr_64_b;
        *ptr_64_b = *ptr_64_a - *ptr_64_b;
        *ptr_64_a = *ptr_64_a - *ptr_64_b;

        sze -= SZE64;
        ptr_64_a++, ptr_64_b++  ;
    }

    uint8_t* ptr_8_a = (uint8_t*)ptr_64_a;
    uint8_t* ptr_8_b = (uint8_t*)ptr_64_b;

    while (sze > 0)
    {
        *ptr_8_a = *ptr_8_a + *ptr_8_b;
        *ptr_8_b = *ptr_8_a - *ptr_8_b;
        *ptr_8_a = *ptr_8_a - *ptr_8_b;
        
        sze -= SZE8;
        ptr_8_a++, ptr_8_b++  ;
    }
}

void memswap_add32(void* a, void* b, size_t sze)
{
    uint32_t* ptr_32_a = (uint32_t*)a;
    uint32_t* ptr_32_b = (uint32_t*)b;

    while (sze >= SZE32)
    {
        *ptr_32_a = *ptr_32_a + *ptr_32_b;
        *ptr_32_b = *ptr_32_a - *ptr_32_b;
        *ptr_32_a = *ptr_32_a - *ptr_32_b;

        sze -= SZE32;
        ptr_32_a++, ptr_32_b++  ;
    }

    uint8_t* ptr_8_a = (uint8_t*)ptr_32_a;
    uint8_t* ptr_8_b = (uint8_t*)ptr_32_b;

    while (sze > 0)
    {
        *ptr_8_a = *ptr_8_a + *ptr_8_b;
        *ptr_8_b = *ptr_8_a - *ptr_8_b;
        *ptr_8_a = *ptr_8_a - *ptr_8_b;
        
        sze -= SZE8;
        ptr_8_a++, ptr_8_b++  ;
    }
}

void memswap_add8(void* a, void* b, size_t sze)
{
    uint8_t* ptr_8_a = (uint8_t*)a;
    uint8_t* ptr_8_b = (uint8_t*)b;

    while (sze > 0)
    {
        *ptr_8_a = *ptr_8_a + *ptr_8_b;
        *ptr_8_b = *ptr_8_a - *ptr_8_b;
        *ptr_8_a = *ptr_8_a - *ptr_8_b;
        
        sze -= SZE8;
        ptr_8_a++, ptr_8_b++  ;
    }
}