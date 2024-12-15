/*
* Name: Fariha Alam
* Student ID: 230014859
* Course: IN2029 Programming in C++
* Coursework 1
* Brief summary of file: it implements the functionality defined in the Transactions.h class
*/



#include "Transactions.h"

using namespace std;

//adds a purchase to the transactions map or updates the price of an existing item
//requires: item is a valid string, price is a non-negative value
void Transactions::addPurchase(const string& item, double price) {
    purchases[item] = price;
}


//calculates the total cost of all purchases
//requires: purchases contains at least one item
double Transactions::getTotal() const {
    double total = 0;
    
    //iterate through the purchases map, summing up the prices of all items
    for (const auto& [item, price] : purchases) {
        total += price;
    }
    
    return total;
}

//provides read-only access to the purchases map
//requires: purchases is not modified outside this function
const map<string, double>& Transactions::getPurchases() const {
    return purchases;
}
