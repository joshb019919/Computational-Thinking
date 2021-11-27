// Read two integers from the user.  Store one as the number to
// convert to binary and the other as the base to which to
// convert and output the converted number.

// printf, scanf
#include <stdio.h>

// Macros for highest user-entered int and length of binary num
#define SIZE 5
#define MAX 31

// Prototypes
void print(int arr[], int base);
int * convert(int input, int base);


int main(void)
// Set vars to -1 to start while loops

// Make sure user enters int between 0 and 31, inclusive
// Store first int in input

// Make sure user enters int between 2 and 9, inclusive
// Store second int in base

// Output converted integer
{
    int input = -1;
    int base = -1;

    while ( input < 0 || input > MAX )
    {
        printf("Enter a number between 0 and 31: ");
        scanf("%d", &input);
    }

    while ( base < 2 || base > 9 )
    {
        printf("Enter a base between 2 and 9: ");
        scanf("%d", &base);
    }

    print( convert(input, base), base );
    return 0;
}


void print(int arr[], int base)
// Loop through and output binary numbers from bin array
{
    printf("In base %d, your number is: ", base);
    for ( int i = 0; i < SIZE; i++ )
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}


int * convert(int input, int base)
// Idea to fix "returning address of local variable" by using static int:
// https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm

// Loop through user's inputted int SIZE times

// Convert number to base by using modulus of base
// Store converted number in bin
// Divide user's number by base each cycle

// Return bin array of binary numbers
{
    static int bin[SIZE];

    for ( int i = 0; i < SIZE; i++ )
    {
        bin[SIZE-i-1] = input % base;
        input /= base;
    }

    return bin;
}
