// Take user input for a cell phone plan.

// User enters the number of lines on the customer's account,
// and the number of minutes and texts and gigabytes of data
// used across the whole account.

// User may enter y or Y to continue and anything else to quit.

#include <iostream>
#include <iomanip>
using namespace std;

void inputCustomer(int *lines, int *minutes, int *texts, int *data);
double calculateCost(int, int, int, int);

int main(void)
// Prompt the user for each customer's monthly amounts
// Store the amounts as integers
// Call calculateCost to take in the amounts, multiply, return
// Output the customer's final monthly bill
{
    // Whether or not there is a customer to enter and inputs
    char customer = 'Y';
    int lines, minutes, data, texts;

    // Output is fixed to two-decimal point floats.
    cout << setprecision(2) << fixed;

    while (customer == 'Y' || customer == 'y')
    {
        inputCustomer(&lines, &minutes, &texts, &data);
        cout << "Cost: $";
        cout << calculateCost(lines, minutes, texts, data) << endl;

        cout << "Another customer? (Y or y to continue): ";
        cin >> customer;
    }

    return 0;
}


void inputCustomer(int *lines, int *minutes, int *texts, int *data)
// Take input and place the values at the addresses of each pointer
{
    cout << "Enter number of lines on the account: ";
    cin >> *lines;
    cout << "Enter minutes used: ";
    cin >> *minutes;
    cout << "Enter number of texts sent and received: ";
    cin >> *texts;
    cout << "Enter gigabytes of data used: ";
    cin >> *data;
}


double calculateCost(int lines, int minutes, int texts, int data)
// Each line is $6.00
// Calls are $0.02 per minutes
// Texts are $0.0025 each
// Each gigabyte of data is $10.00
{
    double cost_lines = lines * 6;
    double cost_minutes = minutes * .02;
    double cost_texts = texts * .0025;
    double cost_data = data * 10;

    return cost_lines + cost_minutes + cost_texts + cost_data;
}
