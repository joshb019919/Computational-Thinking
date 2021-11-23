// Ask the user to enter a number of minutes and then
// display it in the format weeks, days, hours, minutes.

// DISPLAY CALCULATIONS:
// Divide the number of user-entered minutes by the number
// of minutes in that time period.  For instance, the number
// of weeks is the number of days per week times the number
// of hours per day times the number of minutes per hour.

// REDUCTION CALCULATIONS:
// Reduce the original input number of minutes by the number
// of minutes required to increase the number of days, weeks,
// or hours above 0.  The final number of minutes below 60 is
// the number left over after all other calculations.

// cout, cin
#include <iostream>

// macros: days per week, hours per day, minutes per hour
#define DAYS 7
#define HOURS 24
#define MINUTES 60

using namespace std;

int main()
{
    // Use a long int for checking very large number of days
    long total_minutes = -1;

    while (total_minutes < 0)
    {
        // Store user input in total_minutes at least 0
        cout << "Enter a number of minutes: ";
        cin >> total_minutes;
    }

    // Total weeks and total_minutes reduction calculation
    int weeks = total_minutes / (DAYS * HOURS * MINUTES);
    total_minutes %= (7 * 24 * 60);

    // Total days and total_minutes reduction calculation
    int days = total_minutes / (HOURS * MINUTES);
    total_minutes %= (24 * 60);

    // Total hours and total_minutes reduction calculation
    int hours = total_minutes / MINUTES;
    total_minutes %= 60;

    // Leftover minutes after reduction calculations
    int minutes = total_minutes;

    cout << "This represents: " << weeks << " weeks, " << days << " days, " << hours << " hours, and " << minutes << " minutes"
         << "\n";

    return 0;
}