// HEADER COMMENTS
// Ask the user to enter information about three book collections.
// Each collection has a number of volumes and a price per volume
// (same for each volume in the collection).

// Ask how many volumes and what is the price per volume for each
// collection, as well as a budget available for a buyer named Bob.

// All values entered should be integers. The program should
// evaluate a set of logical expressions and print out specific
// messages based on the truth value of those expressions

// SUMMARY:
// user enters for 3 book collections:
//    each collection has an integer number of volumes
//        each volume has an integer unit price

// user enters Bob's Budget

// eg. 3 collections
//    5 volumes at $7 per
//    4 volumes at $3 per
//    7 volumes at $12 per

// eg. $127

// CONDITIONALS
// check if Bob has budget above 0
//     Bob has some money to buy collections.
//     or
//     Bob does not have money to buy anything.

// check if Bob has enough for all the collections listed
//     Bob has enough money to buy all three collections.
//     or
//     Bob does not have enough money to buy all three collections.

// check if Bob can only afford one collection
//     At least two collections are more expensive than Bob’s budget.
//     or
//     At least two collections are cheaper than or equal to Bob’s budget.

// check if any two collections are identical in price
//     At least two collections cost the same amount of money.
//     or
//     No two collections have the same price.

// check opposite of above: if Bob can only afford one collection
//     Only one collection is cheaper than or equal to Bob’s budget.
//     or
//     More than one collection is cheaper than or equal to Bob’s budget or they are all more expensive.

// required input display and collection:
// Enter volumes and price per volume for collection 1: 2 20
// Enter volumes and price per volume for collection 2: 3 30
// Enter volumes and price per volume for collection 3: 4 50
// Enter Bob’s budget: 100

// required output display:
// (1) Bob has some money to buy collections.
// (2) Bob does not have enough money to buy all three collections.
// (3) At least two collections are cheaper than or equal to Bob’s budget.
// (4) No two collections have the same price.
// (5) More than one collection is cheaper than or equal to Bob’s budget or they are all more expensive.

// printf, scanf
#include <iostream>
using namespace std;

// Prototypes
bool afford_all(int budget, int coll1, int coll2, int coll3);
bool afford_two(int budget, int coll1, int coll2, int coll3);
bool afford_one(int budget, int coll1, int coll2, int coll3);
bool two_equal(int coll1, int coll2, int coll3);


int main(void)
{
    int vols1, price1;
    int vols2, price2;
    int vols3, price3;
    int budget;

    cout << "Enter volumes and price per volume for collection 1: ";
    cin >> vols1 >> price1;

    cout << "Enter volumes and price per volume for collection 2: ";
    cin >> vols2 >> price2;

    cout << "Enter volumes and price per volume for collection 3: ";
    cin >> vols3 >> price3;

    cout << "Enter Bob's budget: ";
    cin >> budget;

    // Prices for each entire collection
    int coll1_price = vols1 * price1;
    int coll2_price = vols2 * price2;
    int coll3_price = vols3 * price3;

    switch (budget)
    {
        // Bob's budget
        case 0: cout << "(1) Bob does not have money to buy anything." << endl; break;
        default: cout << "(1) Bob has some money to buy collections." << endl;
    }

    switch (afford_all(budget, coll1_price, coll2_price, coll3_price))
    {
        // Bob can afford all three collections
        case false: cout << "(2) Bob does not have enough money to buy all three collections" << endl; break;
        default: cout << "(2) Bob has enough money to buy all three collections." << endl;
    }

    switch (afford_two(budget, coll1_price, coll2_price, coll3_price))
    {
        // Bob can afford any two collections out of the three
        case false: cout << "(3) At least two collections are more expensive than Bob's budget." << endl; break;
        default: cout << "(3) At least two collections are cheaper than or equal to Bob's budget." << endl;
    }

    switch (two_equal(coll1_price, coll2_price, coll3_price))
    {
        // At least two of the collections are the same price
        case false: cout << "(4) No two collections have the same price." << endl; break;
        default: cout << "(4) At least two collections cost the same amount of money." << endl;
    }

    switch (afford_one(budget, coll1_price, coll2_price, coll3_price) &&
            !afford_two(budget, coll1_price, coll2_price, coll3_price))
    {
        // Bob can only afford one collection
        case false: cout << "(5) More than one collection is cheaper than or equal to Bob’s budget or they are all more expensive." << endl; break;
        default: cout << "(5) Only one collection is cheaper than or equal to Bob’s budget." << endl;
    }

    return 0;
}


bool afford_all(int budget, int coll1, int coll2, int coll3)
{
    if (budget >= coll1 + coll2 + coll3)
    {
        return true;
    }

    return false;
}


bool afford_two(int budget, int coll1, int coll2, int coll3)
{
    if ((budget >= coll1 && budget >= coll2) ||
        (budget >= coll1 && budget >= coll3) ||
        (budget >= coll2 && budget >= coll3))
    {
        return true;
    }

    return false;
}


bool afford_one(int budget, int coll1, int coll2, int coll3)
{
    if ((budget >= coll1 || budget >= coll2 || budget >= coll3))
    {

        return true;
    }

    return false;
}


bool two_equal(int coll1, int coll2, int coll3)
{
    if ((coll1 == coll2) ||
        (coll1 == coll3) ||
        (coll2 == coll3))
    {
        return true;
    }

    return false;
}
