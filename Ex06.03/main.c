#include <stdio.h>

#include "Ex06.03.h"

int main(void)
{

    char character;
    //printf_s("Enter a single character: ");
    //scanf_s("%c", &character, sizeof(character));
    character = 'A';
    PrintBin(&character, sizeof(character));
    printf_s("\n");

    
    int inputNumber;
    //printf_s("Enter an integer number: ");
    //scanf_s(" %d", &inputNumber);
    inputNumber = 0x11223344;
    PrintBin(&inputNumber, sizeof(inputNumber)); 
    return 0;
}
