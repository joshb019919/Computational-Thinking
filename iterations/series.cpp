// Time your c++ program

// As found in:
// https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int n = 0;
    int sum = 0;

    cout << "Enter an integer number: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        // Mathematical algorithm
        // sum += pow(i, 2) * pow(-1, i + 1);

        // Procedural algorithm
        if (i % 2 == 0)
        {
            sum -= i * i;
        } else {
            sum += i * i;
        }
    }

    cout << "The value of the series is: " << sum << endl;

    return 0;
}
