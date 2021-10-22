// Take in a user inputted string ended by a period.
// Count and output the number occurrance of each letter in the string.

#include <iostream>
using namespace std;

int main(void)
{
    // Counts to be incremented as letters are found in user's sentence
    int counts[26] = {0};

    cout << "Enter a sentence (end by .): ";

    // int c read as between 97 and 122, inclusive, on the ASCII table
    int c = tolower(getchar());

    // Loop through user's sentence till a literal '.' is found
    while (c != '.')
    {
        // c - a is indexes 0-26 for counts array and letters a-z
        if (c >= 'a' && c <= 'z')
        {
            // Increment values of counts array as letters are found
            counts[c - 'a']++;
        }

        // Take next char from stdin
        c = tolower(getchar());
    }

    // Loop over and output letter counts
    for (int i = 0; i < 26; i++)
    {
        // Skip letters not found
        if (counts[i] == 0)
        {
            continue;
        }

        // i + a gives lowercase letter and counts[i] is the count of that letter
        cout << "Occurences of '" << (char)(i + 'a') << "': " << counts[i];
        cout << endl;
    }

    return 0;
}