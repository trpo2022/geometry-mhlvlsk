#include <stdio.h>
#include "inputread.h"

void initInput(char array[32])
{
    char prefix[] = "(geometry) ";
    printf("%s", prefix);
    scanf(" %[^\n]", array);
}
