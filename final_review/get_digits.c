// Loop through a alpha-numeric string and store its numbers in another
// string for display.

#include <stdio.h>

int main(void)
// Create the strings to hold the alnum string and the numeric string
// Create char pointers to traverse the char arrays
// Traverse the alnum string and assign numbers to the numeric string
// Add the null terminator to the numeric string
// Output the numeric string
{
    char *str = "a05tk0si9";
    char digits[15];

    char *p = str;
    char *q = digits;

    while (*p)
    {
        if (*p >= '0' && *p <= '9')
        {
            *q = *p;
            q++;
        }
        p++;
    }

    *q = '\0';

    printf("%s\n", digits);

    return 0;
}
