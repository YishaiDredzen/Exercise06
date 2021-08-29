#include "Ex06.03.h"

#include <stdio.h>

#define BYTE_SIZE 7

void PrintBin(void *address, int size)
{
    unsigned char *ptr = address;
    for (int index = 0; index < size; ++index)
    {
        for (int j = BYTE_SIZE; j >= 0; j--) {
            printf("%d", (ptr[index] >> j) & 1); //or each bit and shift by 1
            if (j%4==0)
            {
                printf_s(" ");
            }
        }
        printf_s("\n");
    }
}
