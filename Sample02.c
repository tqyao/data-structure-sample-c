#include <stdio.h>

int main(void)
{
    int number;
    char text[20] = "abc";

    printf("Enter a number: ");
    scanf("%d", &number);

    sprintf(text, "%d", number);

    printf("\nYou have entered: %s", text);

    return 0;
}