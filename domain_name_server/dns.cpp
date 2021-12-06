// Prompt the user for a host's domain name, eg. www.google.com or
// google.com, and return the host's IP address, eg. 64.119.82.224.

// Store the domains' names and addresses in a array of structures.

// Resolution to error feeding file input stream to reader function
// found at StackOverflow by user Theolodis:
// https://stackoverflow.com/questions/23603735/attempting-to-reference-a-deleted-function

// Lesson learned:
// Using the pointer to the object passes the original by reference
// rather than attempting to use a now-deleted copy constructor to
// pass a copied value.

// Including cout, cin, ifstream, and string functionalities
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct MyHost
// Domain name is readable url name, eg. www.google.com
// IP Address is machine server address, eg. 64.120.344.1
{
    string domain_name;
    string ip_address;
};

void input(ifstream&, MyHost*, int n);
void output(string*, MyHost*, int n);

int main(void)
// Open domain name server text file
// Check to make sure file opened correctly
// Read first line of servers file as number of servers listed
// Initialize the array of MyHost servers
// Read the values from the txt file into the array
// Close the file stream
// Continually ask the user for a domain name
// Until user enters "quit", provide that domain's IP address
{
    // Open file stream
    ifstream f;
    f.open("dns.txt");

    // Ensure file stream is open
    if (!f.is_open())
    {
        // Text file not found
        cout << "file not found" << endl;
        return -1;
    }

    // Store rows of server data in text file
    // f >> automatically advances stream pointer
    int num_servers;
    f >> num_servers;

    // Create server array space and store server structures
    MyHost servers[num_servers];
    input(f, servers, num_servers);

    // Close file stream
    f.close();

    // Prompt user for domain of which to find IP address
    string domain;

    // Ask forever
    while (1)
    {
        // Store user's entry
        cout << "Enter domain name: ";
        cin >> domain;

        // User entered "quit"
        if (domain == "quit") break;

        // Search for domain and output IP address
        output(&domain, servers, num_servers);
        cout << endl;
    }

    return 0;
}

void input(ifstream &f, MyHost *servers, int n)
// Read file stream's tab separated values into buffer
// Store host domain names and ip addresses in MyHost array
{
    // Parse the MyHost array
    for (int i = 0; i < n; i++)
    {
        // Store domain name and ip address from file stream
        // f >> automatically advances stream pointer
        MyHost *host;
        f >> host->domain_name;
        f >> host->ip_address;

        // Assign host structure value as server value at pointer
        // Advance servers array pointer
        *servers++ = *host;
    }
}

void output(string *domain, MyHost *arr, int n)
// Search the array of MyHost data structures
// Compare user entered domain against stored hosts
// Output ip address of domain if found
// Else output not found
{
    // Parse the MyHost array
    for (int i = 0; i < n; i++)
    {
        // Domain found
        if (arr->domain_name == *domain)
        {
            // Output domain name, tab-space, IP address
            // Exit function
            cout << arr->domain_name << '\t';
            cout << arr->ip_address << endl;
            return;
        }

        // Increment array pointer
        arr++;
    }

    // Domain not found
    cout << "Domain name not found" << endl;
}
