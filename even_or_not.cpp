// Ask the user for 4 integers, w, x, y, and z.
// Evaluate and output the following:
//     whether or not x is the smallest
//     whether or not w + x <= y + z
//     whether or not all four integers are even

// cout, scanf
#include <iostream>
using namespace std;

int main(void)
{
    int w = 0, x = 0, y = 0, z = 0;

    // Ask for and take integers
    // Used scanf because taking input with commas
    // with cin was going to be more difficult than
    // necessary
    cout << "Enter 4 integers (w, x, y, z): ";
    scanf("%d, %d, %d, %d", &w, &x, &y, &z);

    // Condition 1 test
    cout << "Condition 1 is ";
    if (x < y && x < z && x < w)
    {
        cout << "true."
             << "\n";
    }
    else
    {
        cout << "false."
             << "\n";
    }

    // New variables for condition 2 test
    int sum1 = w + x;
    int sum2 = y + z;

    // Condition 2 test
    cout << "Condition 2 is ";
    if (sum1 <= sum2)
    {
        cout << "true."
             << "\n";
    }
    else
    {
        cout << "false."
             << "\n";
    }

    // More new variables for condition 3 test
    int s = w % 2 == 0;
    int t = x % 2 == 0;
    int u = y % 2 == 0;
    int v = z % 2 == 0;

    // All even or not
    int even = s && t && u && v;

    // Condition 3 test
    cout << "Condition 3 is ";
    if (even)
    {
        cout << "true."
             << "\n";
    }
    else
    {
        cout << "false."
             << "\n";
    }

    return 0;
}
