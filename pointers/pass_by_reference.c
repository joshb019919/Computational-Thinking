// C and C++ are normally pass-by-value in functions.  Demonstrate
// pass-by-reference using pointers and a second function.

#include <stdio.h>

int *pointing(int arr[], int len);

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};

    printf("%d\n", *pointing(arr, 5));

    return 0;
}

int *pointing(int arr[], int len)
{
    return &arr[3];
}
