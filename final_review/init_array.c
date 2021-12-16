// Build a dynamically allocated array of size 'rows'

// The array should hold values from 1 up to rows, with each column and
// row incrementing by one as follows:

// 1 2 3
// 2 3 4
// 3 4 5

#include <stdio.h>
#include <stdlib.h>

int *init_array(int rows)
// Take number of rows to malloc
// Malloc rows of size int across 3 columns
// Assign dynamically allocated array into an integer pointer
// Loop through the array and assign the properly incremented values
// Return the pointer
{
    int *arr = malloc(sizeof(int) * rows * 3);
    for (int i = 0; i < rows; i++)
    {
        arr[i*3 + 0] = i+1;
        arr[i*3 + 1] = i+2;
        arr[i*3 + 2] = i+3;
    }

    return arr;
}

int main(void)
// Dynamically allocate the array to a pointer to an integer
// Loop through and display each row
// Free the dynamically allocated array memory
{
    int *my_array;
    my_array = init_array(3);

    for (int i = 0; i < 9; i+=3)
    {
        printf("%d %d %d\n", my_array[i], my_array[i+1], my_array[i+2]);
    }

    free(my_array);

    return 0;
}
