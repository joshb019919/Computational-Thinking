// Read an integer entered by the user and display it in binary.

// printf, scanf
#include <stdio.h>

// Macros for highest user-entered int and length of binary num
#define SIZE 5
#define MAX 31

// Prototypes for conversion and output functions
void print(int arr[]);
int * convert(int input);


int main(void)
// Set var to -1 to start while loop

// Make sure user enters int between 0 and 31, inclusive
// Store first int in input

// Output converted integer
{
    int input = -1;

    while ( input < 0 || input > MAX )
    {
        printf("Enter a number between 0 and 31: ");
        scanf("%d", &input);
    }

    print( convert(input) );

    return 0;
}


void print(int arr[])
// Loop through and output binary numbers from bin array
{
    printf("In binary, your number is: ");
    for ( int i = 0; i < SIZE; i++ )
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}


int * convert(int input)
// Idea to fix "returning address of local variable" warning:
// https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm

// Loop through user's inputted int SIZE times

// Convert number to binary by using modulus of 2
// Store converted number in bin
// Divide user's integer by 2 each cycle

// Return bin array of binary numbers
{
    static int bin[SIZE];

    for ( int i = 0; i < SIZE; i++ )
    {
        bin[SIZE-i-1] = input % 2;
        input /= 2;
    }

    return bin;
}
