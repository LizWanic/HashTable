/*
Name      : Elizabeth Wanic
Date      : 7 December 2016
File Name : HA3_Wanic.cpp
Task      : As per Home Assignment 3 instructions:
        	Implement a hash table for storing nodes defined on lines 5-8 of
        	the list.cpp file:
        	struct Node {
				int data;
				Node * next;
        	}
        	Both key and data are represented by data.
        	Define a class HashTable where buckets are implemented as objects of
        	the class List, by redefining the List class in list.cpp.  Rename the
        	file as list_MyName.h and include it in main. 

        	The HashTable class should have the following member functions:
        		normal constructor, with parameter N for hash table's array size
        		int total_number() - number of nodes in the hash table
        		void add(int new_key) - will allow several instances of a node
        				with the same key
        		void print_table() - prints the contents of the hash table, print
        				'empty' if table is empty
        		bool find(int x) - returns true if found, false if not
		
        	Create a main() function that does the following:
				a) Define a variable HashTable H1 and populate it with random 
				   numbers.  Print the number of stored nodes and the contents
				   of the table after each operation
				b) Demonstrate that find() works for successful and unsuccessful
				   searches
				c) Add a destructor for extra bonus points  */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include "list_Wanic.h"
using namespace std;

//--------------------------------------
class HashTable {

	int size;
	List * table; // array of buckets

	// hash function
	int hash(int key){
		return abs(key) % size; 
	}

public:
	HashTable(int N);
	~HashTable();
	void add(int new_key);
	bool find(int x); 
	int total_number();
	void print_table();
	
};// end class HashTable
//---------------------------------------

	HashTable::HashTable(int N) {
        cout<<"\nHashTable constructor called\n";
        size = N;
		table = new List [size];
		// create empty Lists
    }

    HashTable::~HashTable() {
    	cout<<"\nHashTable destructor called\n";
		for(int i=0; i < size; i++) {
			table[i].~List();
		}
    } 

    void HashTable::add(int new_key) {
		int index = hash(new_key);
		table[index].push(new_key);
    }

	bool HashTable::find(int x) {

        return table[hash(x)].find(x);
	}

	int HashTable::total_number() {
		cout<<"\nHash table with "<< size<<" buckets ";
		int total =0;
			for(int i=0; i< size; ++i){ 
				total += table[i].length();
			}	
        if (total == 1){
            cout<<"and "<< total <<" element.\n";
        }else{
            cout<<"and "<< total <<" elements.\n";
        }

		return total;
	}

	void HashTable::print_table(){

		for(int i=0; i< size; ++i){
			cout<<"Bucket "<< i << ":\n"; 
			table[i].print();
		}	
}
//-------------------------------------------------

int main(){
	//Declare local variables
	int value;
	int y;
	int x;
    int z;

	//Define a variable HashTable H1 
	HashTable H1(4);

    //Seed the random number generator
    srand(time(NULL));

	//Populate H1 with 7 random numbers
	//Print the number of stored nodes and 
	//the contents of the table after each operation
	for(int i=0; i< 7; ++i){
		value = rand()%100;
		H1.add(value);
		H1.total_number();
		H1.print_table();
	}

    //Adding a negative number
	H1.add(-4);
    H1.total_number();
    H1.print_table();

	//Demonstrate that find() works 
	//Successful case - using value which is holding the last random number added
	cout<<"\nDemonstrating successful case of the find() function.\n";
	cout<<"Checking for the value "<< value <<".\n";
	y = H1.find(value);

	if (y != 0) {
		cout<<"The value "<< value <<" was found.\n\n";
	//Should not get here
    }else{
		cout<<"The value "<< value <<" was not found.\n\n";
	}
	//Unsuccessful case
    //Using a number higher than the max random value
	cout<<"\nDemonstrating unsuccessful case of the find() function.\n";
	cout<<"Checking for the value 123.\n";
	x = H1.find(123);
	if (x == 0) {
		cout<<"The value 123 was not found.\n\n";
	//Should not get here
    }else{
		cout<<"The value 123 was found.\n\n";
	}

    //Checking for a negative number
    cout<<"\nDemonstrating checking for a negative number.\n";
    cout<<"Checking for the value -4.\n";
    z = H1.find(-4);
    if (z == 0) {
        //Should not print here
        cout<<"The value -4 was not found.\n\n";
    //Should print here
    }else{
        cout<<"The value -4 was found.\n\n";
    }
    //Destructors will be called when the program exits
	return 0;
}
