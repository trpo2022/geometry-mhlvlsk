#include <stdio.h>
#include <string.h>

int main ()
{
    char input[64];
    printf("Enter a figure: \n");
    scanf("%s", &input);
    
    if (strcmp(input, "circle") == 0)
        printf("You entered a circle \n");
}
