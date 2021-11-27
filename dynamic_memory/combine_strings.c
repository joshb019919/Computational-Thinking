// Take two user-entered strings and one or both of two flags
// upon launching the program.  If -i flag is used, weave the two
// strings together like a zipper.  If -w flag is used, concatenate the
// two strings together with asterisks between each character.  If both
// flags are used, do both.  Does not account for each flag supplied in
// two separate dashes, "-i -w" won't work.

// printf, scanf, malloc, free
#include <stdio.h>
#include <stdlib.h>

// Max length of strings
#define MAX_LEN 30

char *intersperse(const char *str1, const char *str2);
char *widen_stars(const char *str1, const char *str2);
void input(char *str);
unsigned short str_len(const char *str);

int main(int argc, char **argv)
// Reserve space for two strings, max 30 chars plus NULL terminator
// Accept two strings from user input
// If argv == i, intersperse the strings into a new string & output
// If argv == w, widen_stars the two strings into a new string & output
// Free any used memory
{
    // Exactly 2 command line args
    if (argc != 2)
    {
        printf("USAGE: ./combine_strings -i or\n");
        printf("       ./combine_strings -w or\n");
        printf("       ./combine_strings -iw\n");

        exit(-1);
    }

    // Strings 1 and 2
    char str1[MAX_LEN + 1];
    char str2[MAX_LEN + 1];

    // Input function
    input(str1);
    input(str2);

    // Determine which flags are used
    while (*argv[1])
    {
        // -i intersperse operation
        if (*argv[1] == 'i')
        {
            char *str3 = intersperse(str1, str2);
            printf("%s\n", str3);
            free(str3);
        }

        // -w widen_stars operation
        if (*argv[1] == 'w')
        {
            char *str3 = widen_stars(str1, str2);
            printf("%s\n", str3);
            free(str3);
        }

        *argv[1]++;
    }

    return 0;
}

char *intersperse(const char *str1, const char *str2)
// Allocate memory for a new string on the heap
// Use a travelling pointer to assign chars to the new string
// Interlace two other strings together into the new string
// Lace str1's char, then str2's, str1's next char, etc. like a zipper
// A longer string's chars are simply concatenated to the end
// Return a pointer to the new string
{
    // Space for strings and NULL terminator
    char *interspersed_str = (char*) malloc(str_len(str1) + str_len(str2) + 1);
    char *trv = interspersed_str;

    // Not enough memory
    if (!interspersed_str)
    {
        printf("NOT ENOUGH MEMORY!!\n");
        exit(1);
    }

    // Add str1 and str2 chars to new str, alternating back and forth
    while (*str1 || *str2)
    {
        if (*str1)
            *trv++ = *str1++;
        if (*str2)
            *trv++ = *str2++;
    }

    // Add NULL terminator
    *trv = '\0';

    return interspersed_str;
}

char *widen_stars(const char *str1, const char *str2)
// Allocate memory for a new string on the heap
// Use a travelling pointer to assign chars to the new string
// Add str1 to new string, then str2
// Add an asterisk between each char of the new string
{
    // Space for strings, asterisks, and NULL terminator
    char *widened_str = (char*) malloc(str_len(str1) * 2 + str_len(str2) * 2);
    char *trv = widened_str;

    // Not enough memory
    if (!widened_str)
    {
        printf("NOT ENOUGH MEMORY!!\n");
        exit(1);
    }

    // Add asterisk-widened str1 chars to new string
    while (*str1)
    {
        *trv++ = *str1++;
        *trv++ = '*';
    }

    // Add asterisk-widened str2 chars to new string
    while (*str2)
    {
        *trv++ = *str2++;
        *trv++ = '*';
    }

    // Overwrite final asterisk with NULL terminator
    *(trv - 1) = '\0';

    return widened_str;
}

unsigned short str_len(const char *str)
// Use a char pointer to traverse the string till NULL terminator
// Return length of string from traversal ptr to original str ptr
{
    const char *trv = str;
    while (*trv) trv++;
    return trv - str;
}

void input(char str[])
// Prompt user for input with max possible chars
// Assign input to str array
{
    // Repeats if user enters 31+ chars
    while (1)
    {
        printf("Please enter a string of maximum 30 characters: ");
        scanf("%s", str);

        // User entered fewer than 31 chars
        if (str_len(str) <= MAX_LEN)
        {
            break;
        }
    }

}
