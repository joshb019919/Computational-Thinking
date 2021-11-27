// Take the length, width, and height of a rectangular prism
// and calculate the surface area and volume of the prism.

// Accept only integers and use two separate functions for
// the calculations.

// Output the area and volume and make sure the user enters
// only positive values for the length, width, and height.

#include <stdio.h>

int compute_area(int l, int w, int h);
int compute_volume(int l, int w, int h);

int main(void)
// Prompt the user to enter length, width, and height
// Store each value as integers
// Ensure user enters only positive values
// Call the calculation functions and output the results
{
    int l = 0, w = 0, h = 0;
    printf("Enter the dimensions of the square prism (l, w, h): ");
    scanf("%d, %d, %d", &l, &w, &h);

    while (!(l > 0) || !(w > 0) || !(h > 0))
    {
        printf("Please enter positive dimensions for the square prism: ");
        scanf("%d, %d, %d", &l, &w, &h);
    }

    printf("The area of the prism is: %d\n", compute_area(l, w, h));
    printf("The volume of the prism is %d\n", compute_volume(l, w, h));

    return 0;
}

int compute_area(int l, int w, int h)
// Surface area is twice the area of each side
{
    return (2 * l * w) + (2 * l * h) + (2 * w * h);
}

int compute_volume(int l, int w, int h)
// Volume is length * width * height
{
    return l * w * h;
}