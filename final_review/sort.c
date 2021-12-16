// Sort four letter-characters in ascending order

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
// Temporary char holds value in a
// Swap value in a with value in b
// Swap value in b with value in tmp
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(char *a, char *b, char *c, char *d)
// Use a number of conditional tests to bubble sort the chars
{
    // Move highest char to the end
    if (*a > *b) swap(a, b);
    if (*b > *c) swap(b, c);
    if (*c > *d) swap(c, d);

    // Move second-highest char to the second from the end
    if (*a > *b) swap(a, b);
    if (*b > *c) swap(b, c);

    // Move second-lowest char to the second from the beginning
    if (*a > *b) swap(a, b);

    // First char is already lowest
}

int main(void)
// Assign chars
// Output unordered chars
// Sort the chars
// Output ordered chars
{
    char a = 'l';
    char b = 'g';
    char c = 'o';
    char d = 'a';

    printf("%c %c %c %c\n", a, b, c, d);
    sort(&a, &b, &c, &d);
    printf("%c %c %c %c\n", a, b, c, d);

    return 0;
}
