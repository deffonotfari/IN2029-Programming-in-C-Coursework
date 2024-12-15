/*
* Name: Fariha Alam
* Student ID: 230014859
* Course: IN2029 Programming in C++
* Coursework 1
* Brief summary of file: reads the 2 text files to track transactions for individuals and display their purchase records.
*/



#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "FileReader.h"

using namespace std;

//reads names from people.txt and populates a vector in order of appearance
//requires: the people.txt file exists and is accessible
void readPeople(vector<string>& people) {
    ifstream peopleFile("people.txt");
    
    //error handling: file not accessible
    if (!peopleFile) {
        cerr << "Error: The people.txt file could not be opened.\n";
        return;
    }
    
    //reads each name from file
    string personName;
    while (peopleFile >> personName) {
        people.push_back(personName);
    }

    //checks if file was empty
    if (people.empty()) {
        cerr << "Error: The people.txt file is empty.\n";
    }
}

//reads transactions from payments.txt and populates the transactions map
//requires: the payments.txt file exists, and contains valid transaction data
void readPayments(map<string, Transactions>& transactions) {
    ifstream paymentsFile("payments.txt");
    if (!paymentsFile) {
        cerr << "Error: The payments.txt file could not be opened.\n";
        return;
    }
    
    string line;
    int lineNumber = 0;     //Line counter
    
    //Following each iteration of the file, it increments the line counter
    while (getline(paymentsFile, line)) {
        ++lineNumber;       //increments line
        
        
        //finds the first non-space character and erases everything before it
        line.erase(line.begin(), find_if(line.begin(), line.end(), [](unsigned char ch) { return !isspace(ch); }));
        
        //deletes trailing spaces after the last non-space character
        line.erase(find_if(line.rbegin(), line.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), line.end());
        
        //Skip if the line is empty after trimming
        if (line.empty()) {
            continue;
        }
        
        //declaring the values needed to be read
        istringstream iss(line);          //line number
        string personName, item;          //personName, item
        double price;                     //price
        
        //attempts to read three values: name, item, and price
        if (!(iss >> personName >> item >> price)) {
            
            //outputs error message when wrong data is given in wrong format
            cerr << "Error: Invalid line format in payments.txt at line " << lineNumber << ": " << line << "\n";
            exit(EXIT_FAILURE);
        }
        
        // Check if there is extra data in the line after the price
        string extraData;
        if (iss >> extraData) {
            
            //outputs error message when extra data is given
            cerr << "Error: Extra data in line in payments.txt at line " << lineNumber << ": " << line << "\n";
            exit(EXIT_FAILURE);
        }
        
        // Add valid entry to transactions
        transactions[personName].addPurchase(item, price);
    }
}
