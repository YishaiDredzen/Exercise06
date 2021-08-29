#include <stdio.h>

#include "Ex06.02.h"

int main(void)
{
    
    char character;
    printf_s("Enter a single character: ");
    scanf_s("%c", &character, sizeof(character));
    PrintHex(&character, sizeof(character));
    printf_s("\n");

    int inputNumber;
    printf_s("Enter an integer number: ");
    scanf_s(" %d", &inputNumber);
    PrintHex(&inputNumber, sizeof(inputNumber));
    return 0;
}