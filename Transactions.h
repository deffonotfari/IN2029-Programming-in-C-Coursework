/*
* Name: Fariha Alam
* Student ID: 230014859
* Course: IN2029 Programming in C++
* Coursework 1
* Brief summary of file: defines a class for managing and storing purchase transactions for a single individual
*/



#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <string>
#include <map>


class Transactions {
    
    //methods are public to allow external access
    public:
        
        //Adds a purchase to the transactions map
        //or updates the price of an existing item
        //requires: item is a valid string, price is a non-negative value
        void addPurchase(const std::string& item, double price);
        
        
        //calculates the total cost of all purchases
        //requires: purchases contains at least one item
        double getTotal() const;
        
        //provides read-only access to the purchases map
        //requires: purchases is not modified outside this function
        const std::map<std::string, double>& getPurchases() const;


    //data is private to ensure controlled and secure access
    private:
        
        //stores item names and their corresponding prices
        std::map<std::string, double> purchases;
};

#endif
