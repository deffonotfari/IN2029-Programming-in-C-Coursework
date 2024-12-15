/*
* Name: Fariha Alam
* Student ID: 230014859
* Course: IN2029 Programming in C++
* Coursework 1
* Brief summary of file: displays the purchase history based on the 2 text files
*/



#include <iostream>
#include <map>
#include <vector>
#include "Transactions.h"
#include "FileReader.h"

using namespace std;

// displays transaction for each person listed in people.txt
void displayTransactions(const map<string, Transactions>& transactions, const vector<string>& people) {
    
    //iterate through the list of people
    for (const auto& person : people) {
        auto it = transactions.find(person);
        
        //check if transactions exist for the person
        if (it != transactions.end()) {
            cout << person <<"\n";
            
            //display each item and its price
            for (const auto& [item, price] : it->second.getPurchases()) {
                cout << item << " " << price << "\n";
            }
            
            //outputting the total price of purchase
            cout << "Total: " << it->second.getTotal() <<"\n";
        }
        
        //inform user that there's no purchases have been recorded for the person
        else {
            cout << person << "\nNo purchases recorded.\n\n";
        }
    }
}

int main() {
    //declaring a list to store names of people and a map to store transactions
    vector<string> people;
    map<string, Transactions> transactions;

    //reads the names of people from people.txt
    readPeople(people);
    
    //reads the transactions from payments.txt
    readPayments(transactions);
    
    //displays transactions for each person
    displayTransactions(transactions, people);

    return 0;
}
