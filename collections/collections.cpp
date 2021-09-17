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

int main(void)
{
    return 0;
}
