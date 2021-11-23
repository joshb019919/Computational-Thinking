// Take two strings of max 50 characters each and use the functions
// strcat, strcmp, strlen, and strcpy to work with them in the
// following manner:

// Output the length of each string on separate lines
// Determine and output which string is first, alphabetically
// Concatenate string 1 onto string 2 and output both strings
// Overwrite string 2's characters with string 1's and output both

// Rules of strcmp alphabetization (in this implementation):
//   Don't count uppercase vs lower
//   Closer to 'a' is lower, closer to 'z' is higher
//   Shorter strings come first if otherwise identical

// Never forget that null terminator!!

#include <ctype.h>
#include <stdio.h>

unsigned short strlen(const char *c);
short strcmp(const char *a, const char *b);
const char* strcat(const char *a, char *b);
const char* strcpy(const char *a, char *b);
void print_order(short num);

int main(void)
// Initialize two character arrays
// Max length 51 (50 chars + null terminator)
// Store different strings from console input into each array
// Utilize each of the four custom string functions
// Output their values
{
    char str1[51];
    char str2[51];

    while (1)
    {
        // Accept both strings of max 50 chars
        printf("Please enter the first string: ");
        scanf("%50s", str1);

        if (strlen(str1) <= 50) break;
    }

    while (1)
    {
        // Over 50 chars goes to next string
        printf("Please enter the second string: ");
        scanf("%50s", str2);

        if (strlen(str2) <= 50) break;
    }

    // String lengths
    printf("The length of string 1 is: %d\n", strlen(str1));
    printf("The length of string 2 is: %d\n", strlen(str2));

    // Alphabetical order of the two strings
    print_order(strcmp(str1, str2));

    // Concatenate string 1 onto the end of string 2
    strcat(str1, str2);
    printf("String 1 after concatenation: %s\n", str1);
    printf("String 2 after concatenation: %s\n", str2);

    // Overwrite string 2 with string 1's characters
    strcpy(str1, str2);
    printf("String 1 after copying: %s\n", str1);
    printf("String 2 after copying: %s\n", str2);

    return 0;
}


unsigned short strlen(const char *c)
// Count and return the number of characters in a string
{
    // Loop d through till end of string c
    const char *d = c;
    while (*++d);

    // Length = position d - position c
    return d - c;
}


short strcmp(const char *a, const char *b)
// Compare two strings for alphabetical placement
// Return 1 if string a is first, -1 if string b is first
// Return 0 if the strings are identical
{
    // Loop through by pointer till the chars are different
    while ( *a && tolower(*a) == tolower(*b) )
        ++a, ++b;

    // String a is first
    if ( tolower(*a) < tolower(*b) )
        return 1;

    // String b is first
    else if ( tolower(*b) < tolower(*a) )
        return -1;

    return 0;
}


const char* strcat(const char *a, char *b)
// Add string a to the end of string b
// Return pointer to string b
{
    // Loop to the end of string b
    while (*b)
        b++;

    // Concatenate a onto b
    while (*a)
        *b++ = *a++;

    // Append null terminator
    *b = '\0';

    return b;
}


const char* strcpy(const char *a, char *b)
// Overwrite string b with string a
// Return a pointer to string b
{
    // Overwrite all b chars with a chars
    while (*a)
        *b++ = *a++;

    // Append null terminator
    *b = '\0';

    return b;
}


void print_order(short num)
{
    switch (num)
    {
        case -1: printf("String 2 comes before string 1, alphabetically.\n");
                break;
        case 0: printf("The two strings are the same.\n");
                break;
        case 1: printf("String 1 comes before string 2, alphabetically.\n");
                break;
    }
}
