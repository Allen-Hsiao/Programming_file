#include <iostream>
#include <vector>
#include "IntList.h"

using namespace std;

IntList::IntList(){
    head = NULL;
    tail = NULL;
}

IntList::~IntList(){
    IntNode* temp;
    
    while( head ) {     
        temp = head; 
        head = head -> next;
        delete temp;
	}
}

//Inserts a data value (within a new node) at the front end of the list.
void IntList::push_front(int inputnum){
    IntNode* temp;
    temp = head;
    head = new IntNode(inputnum);
    head->next = temp;

    // Check if it's no tail
    if (tail == NULL){
        tail = head;
    }
}

// Removes the value (actually removes the node that contains the value) at the front end of the list.
// Does nothing if the list is already empty.
void IntList::pop_front(){
    if (head != NULL && tail != NULL){
        this->head = head->next; //reconnect the head to the next node
    }
}

// Returns true if the list does not store any data values (does not have any nodes)
// otherwise returns false.
bool IntList::empty() const{
    if (head == NULL){ //Only need to check if head have value since tail can be head
        return true;
    }
    return false;
}

// Returns a reference to the first value in the list. 
// Calling this on an empty list causes undefined behavior.
const int & IntList::front() const{
    return head->value;
}

const int & IntList::back() const{
    return tail->value;
}

// Overloads the insertion operator (<<) so that it sends to the output stream (ostream)
// a single line all of the int values stored in the list, each separated by a space. 
// This function does NOT send a newline or space at the end of the line.
ostream &operator<<(ostream &out, const IntList &inputList){
    IntNode* curr = inputList.head;
    while(curr != NULL){
        out << curr->value;
        curr = curr->next;
        
        if(curr != NULL){
            out << " ";
        }
    }
    return out;
}