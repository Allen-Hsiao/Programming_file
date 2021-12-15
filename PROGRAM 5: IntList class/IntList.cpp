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
    
    while(head != NULL) {     
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
        IntNode*temp = head->next; //reconnect the head to the next node
        delete head;
        head = temp;
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

// the copy constructor. Make sure this performs deep copy.
IntList::IntList(const IntList &cpy){
    head = nullptr;
    tail = nullptr;    
    for(IntNode* current = cpy.head; current != nullptr; current = current->next){
        push_back(current->value);
    }
}

// the overloaded assignment operator. Make sure this performs deep copy.
IntList & IntList::operator=(const IntList &rhs){
    if ( this != &rhs){

        head = nullptr;
        tail = nullptr;
        for(IntNode* i = rhs.head; i != nullptr; i = i->next)
        {
            push_back(i->value);
        }
    }
    return *this;
}

// Inserts a data value (within a new node) at the back end of the list.
void IntList::push_back(int value){
    if(head != nullptr)
    {
        IntNode* temp = new IntNode(value);
        tail->next = temp;
        tail = temp;
        
    }

    else{
        head = new IntNode(value);
        tail = head;
    }


}

// Removes (deallocates) all IntNodes in the IntList. 
// Don't forget to set both head and tail to appropriate values for an empty list. 
// DO NOT leave them dangling!
void IntList::clear(){
    IntNode* currnode;
    while(head != NULL){
        currnode = head;
        head = currnode->next;
        delete currnode;
    }
    head = NULL;
    tail = NULL;
}

// Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers.
void IntList::selection_sort(){
    int temp;
	IntNode* min;
	IntNode* i = head;
	IntNode* j;

	if (i != NULL)
	{
		while (i != NULL)
		{
			j = i->next;
			min = i;

			while (j != NULL)
			{
				if (j->value < min->value) //Find the smallest value
					min = j;

				j = j->next;
			}

			temp = i->value;
			i->value = min->value;
			min->value = temp;

			i = i->next;
		}
	}
}

// Inserts a data value (within a new node) in an ordered list. 
// Assumes the list is already sorted in ascending order 
// (i.e., Do not sort the list first, assume the list is already is sorted.) 
// This function loops through the list until if finds the correct position for the new data value 
// and then inserts the new IntNode in that location. This function may NOT ever sort the list.
void IntList::insert_ordered(int value){
    // case1: list is empty
    if (head == NULL){
        head = tail = new IntNode(value);
    }
    // case2: insert value less than head
    else if (head->value > value){
        push_front(value);
    }
    // case3: insert value greater than tail
    else if (tail->value < value){
        push_back(value);
    }
    // case4: insert value greater than head but also less than tail
    else {
        IntNode* i = head;
        IntNode* j = i->next;
        IntNode* insertpoint = new IntNode(value);
        while(j != NULL){
            if (value <= j->value){
                i->next = insertpoint;
                insertpoint->next = j;
                break;
            }
            else{
                i = j;
                j = j->next;
            }
            // i = i->next;
        }
    }
}


// Removes all duplicate data values (actually removes the nodes that contain the values) within the list. 
// Always remove just the later value within the list when a duplicate is found. 
// This function may NOT ever sort the list.
void IntList::remove_duplicates(){
    IntNode* curr = head;
	IntNode* pre = nullptr;
	IntNode* after = nullptr;

    if (curr != nullptr){

        while (curr != nullptr){
            pre = curr;
            after = curr->next;

            while (after != nullptr){
                if (after->value == curr->value){
                    if(after == tail){
                        pre->next = nullptr;
                        tail = pre;    
                        after = nullptr;
                    }
                    else{
                        pre->next = after->next;
                        delete after;
                        after = pre->next;
                    }
                }
                else{
                    if (pre == after){
                        head = tail = pre;
                    }
                    else{
                        pre = after;
                        after= after->next;
                    }
                }
            }

            curr = curr->next;
        }
    }

}