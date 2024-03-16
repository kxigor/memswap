#ifndef MEMSWAP_H
#define MEMSWAP_H

#include <stddef.h>
#include <stdint.h>

typedef enum NumOfBytes
{
    SZE64 = 8UL,
    SZE32 = 4UL,
    SZE8  = 1UL
} NumOfBytes;

void memswap_xor64(void* a, void* b, size_t sze);
void memswap_xor32(void* a, void* b, size_t sze);
void memswap_tmp64(void* a, void* b, size_t sze);
void memswap_tmp32(void* a, void* b, size_t sze);
void memswap_xor8 (void* a, void* b, size_t sze);
void memswap_tmp8 (void* a, void* b, size_t sze);

#endif // !MEMSWAP_H