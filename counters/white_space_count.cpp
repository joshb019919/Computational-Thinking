// Ask the user to enter a sentence ended by a period,
// a question mark, or an exclamation mark and print
// out the number of space characters (spaces, new
// lines, tabs) in that sentence.

#include <iostream>
using namespace std;

int main()
{
    char buffer;
    int space = 0, tab = 0, newl = 1;
    cout << "Enter a sentence (end by ‘.’ or ‘?’ or ‘!’): " << endl;

    while (buffer != '.' && buffer != '?' && buffer != '!')
    {
        scanf("%c", &buffer);
        switch (buffer)
        {
        case ' ':
            space++;
            break;
        case '\t':
            tab++;
            break;
        case '\n':
            newl++;
            break;
        }
    }

    cout << "Number of space characters: " << space << endl;
    cout << "Number of new line characters: " << newl << endl;
    cout << "Number of tabs: " << tab << endl;

    return 0;
}