// Take a user-entered integer and loop that many times.  If the loop
// iterator value, i, is even, subtract its square from a sum total,
// starting at 0.  If i is odd, add its square to that sum.

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
        // Mathematical algorithm (slower, probably because of pow())
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
