// Take the radius of a circle inscribed in a square.
// Output the following features of the circle and square:
//     diameter of circle
//     circumference of circle
//     area of circle
//     perimeter of square
//     area of square
//     difference between square's and circle's areas

// CSC 131 - Class Homework
// Author: Josh Borthick
// Date: 9/2/21
// USAGE: gcc circle.c -o circle
//        ./circle

// printf
#include <stdio.h>

// Pi
#define PI 3.14f

// Take user's input, calculate, and output values
int main(void)
{
    int r = 0;

    printf("This program computes values related to an inscribed circle.\n");
    printf("Enter the value of the radius: ");
    scanf("%d", &r);

    int d = r * 2;
    float circumference = PI * r * 2;
    float circle_area = PI * r * r;
    int perimeter = d * 4;
    int square_area = d * d;
    float diff_area = square_area - circle_area;

    printf("The diameter of the circle is: %d\n", d);
    printf("The circumference of the circle is: %.3f\n", circumference);
    printf("The area of the circle is: %.3f\n", circle_area);
    printf("The perimeter of the square is: %d\n", perimeter);
    printf("The area of the square is: %d\n", square_area);
    printf("The difference between the area of the square and the circle is: %.3f\n", diff_area);

    return 0;
}


