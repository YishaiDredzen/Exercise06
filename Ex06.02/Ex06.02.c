#include "Ex06.02.h"

#include <stdio.h>

void PrintHex(void *address, int size)
{
    unsigned char *ptr = address;
    for (int index = 0; index < size; ++index)
    {
        printf_s("%x\n", ptr[index]);
    }
}
