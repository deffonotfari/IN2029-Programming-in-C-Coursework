/*
* Name: Fariha Alam
* Student ID: 230014859
* Course: IN2029 Programming in C++
* Coursework 1
* Brief summary of file: declares functions for reading data from 2 text files and populating relevant containers.
*/



#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>
#include <map>
#include "Transactions.h"

//reads names from people.txt and populates a vector in order of appearance
//requires: the people.txt file exists and is accessible
void readPeople(std::vector<std::string>& people);


//reads transactions from payments.txt and populates the transactions map
//requires: the payments.txt file exists, and contains valid transaction data
void readPayments(std::map<std::string, Transactions>& transactions);

#endif
