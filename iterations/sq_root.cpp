// Guess the square root of a positive, user-entered number

// Idea about using fixed, setw, and setprecision found from
// users Alnitak and amit kumar:
// https://stackoverflow.com/questions/798046/digit-limitation-from-decimal-point-in-c

// Further reading from CPlusPlus:
// https://www.cplusplus.com/reference/iomanip/setw/

// cin, cout, set2, setprecision, and fabs
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void)
// Use double precision floats to accept a user-entered value
// Set the radicand to -1 to start so the while loop executes
// Set the guess to 1 to start so the loop isn't infinite
// Output each guess and the final guess in output string
{
    double radicand = -1.0;
    double guess = 1.0;

    // Force a positive radicand
    while (radicand < 0)
    {
        cout << "Enter a number: ";
        cin >> radicand;
    }

    for (;;)
    {
        // Accept any guess within .00001 of actual
        if (fabs((guess * guess) - radicand) < .00001)
        {
            break;
        }

        // Fixed to precision of 5 and field width of 10
        cout << fixed << setw(10) << setprecision(5) << guess << endl;

        // new_guess = (old_guess + (input / old_guess)) / 2.0
        guess = (guess + (radicand / guess)) / 2.0;
    }

    cout << "Estimated square root of " << radicand << ": ";
    cout << guess << endl;

    return 0;
}
