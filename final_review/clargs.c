// Accept command line arguments and output each argument with an even
// number of characters.

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
// Loop through the command line arguments
// Check to see if the argument string has an even number of chars
// If so, output that string argument
{
    for (int i = 1; i < argc; i++)
    {
        if (strlen(argv[i]) % 2 == 0)
        {
            printf("%s\n", argv[i]);
        }
    }

    return 0;
}
