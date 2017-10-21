/*
Name      : Elizabeth Wanic
Date      : 7 December 2016
File Name : list_Wanic.h
Description : 
		  Header file for the class List.  For use
		  with the HA3_Wanic.cpp file.  
		  */

// simple linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
};
//---------------------------------
class List {

    Node * head;
	int len;

public:
	// normal constructor
    List() {
		cout<< "Normal List constructor called\n";
        head = NULL;
		len = 0;
    }
	
	// destructor
    ~List() {
		cout<< "List destructor called\n";
        while(head != NULL) {
            Node * n = head->next;
            delete head;
            head = n;
        }
    }
	
	// copy constructor
	List(const List &ob){
		cout<< "\nList copy constructor called\n";
		if(!ob.head) *this = ob;
		else{
			head = new Node;
			*head = *ob.head;
			
			Node * prev = head;
			Node * p = ob.head;
			Node * p2;
			
			while(p = p-> next){
				// create a copy of node
				p2 = new Node;
				*p2 = *p;
				
				// connect the previous with this one
				prev-> next = p2;
				
				prev = p2;
			} // end while
			
			len = ob.len;
		}// end else
	}

    // add element at the beginning of list
    void push(int value) {
        Node * n = new Node;
        n->data = value;
        n->next = head;
        head = n;
		len++;
    }
	
	// retrieve the first element and delete it
	int pop(){
		if(len == 0){
			cout << "\nAttempt to pop empty list\n";
			return 0; 
		
		}else{
			Node * p = head;
			int res = p->data;			
			head = p->next;
			delete p;
			len--;
			return res;
		}
	}
	
    int length(){
		return len;
	}
	
	bool find(int x){
		Node *elt = head;
		while(elt != NULL) {
            if(elt->data == x) return true;
			elt = elt->next;
        };
		return false;
	}
	
	void print(){
		if (head != NULL) {
			Node *elt = head;
			while(elt != NULL) {
				cout << ' ' << elt->data ;
				elt = elt->next;
			}
			cout<< endl;
		} else {
			cout<< " empty";
            cout<< endl;
		}
	}
}; // end of class List



