#include <iostream>
#include "SortedSet.h"

using namespace std;

SortedSet::SortedSet(): IntList(){}


SortedSet::SortedSet(const SortedSet &set): IntList(set){}

// A constructor that is passed an IntList instead of a SortedSet. 
// It should initialize the set using the values in the IntList. 
// Again, you can use the IntList copy constructor 
// and then remove all of the duplicates and sort the remaining values.
SortedSet::SortedSet(const IntList &list): IntList(list){
    IntList::remove_duplicates();
    IntList::selection_sort();
}

// The destructor needs to deallocate all dynamically allocated memory 
// that the IntList destructor will not already deallocate. 
// You may very well find that this function does not need to do anything.
SortedSet::~SortedSet(){}

// This function returns true if the value passed in is a member of the set, otherwise false.
bool SortedSet::in(int value){
    IntNode *cur = head;
    while(cur != nullptr){
        if(cur->value == value){
            return true;
        }
        cur = cur->next;
    }
    return false;
}


// This function returns a SortedSet object that is the union of 2 SortedSet objects, 
// the left and right operands of this binary operator. 
// A union of 2 sets is a set that consists of all of the distinct elements of both sets combined. 
// That is, all of the values that are in the left operand or in the right operand or in both operands.
// sset1 = sset2 | sset3;

// Hint: This operator return type will be very similar to the + operator you implemented for the Distance class.
SortedSet & SortedSet::operator|(SortedSet &set){
    SortedSet* sset = new SortedSet();
    // If one of the sets is nullptr, then the union will be one of them
    if (set.head == nullptr){
        sset = this;
    }
    else if (head == nullptr){
        sset = &set;
    }
    //Two sets both have elements 
    else{
        IntNode* node_front = head;
        IntNode* node_back = set.head;
        //Extract the first element by order
        if (node_front->value < node_back->value){
            sset->push_back(node_front->value);
            node_front = node_front->next;
        }
        else{
            sset->push_back(node_back->value);
            node_back = node_back->next;
        }

        //Extract the rest of elements and add to sset by order
        while (node_front != nullptr && node_back != nullptr) {
            if (node_front->value < node_back->value) {
                sset -> push_back(node_front->value);
                node_front = node_front->next;
            }
            else {
                sset->push_back(node_back->value);
                node_back = node_back->next;
            }
        }
        //If one of sets have been updated elements, the other set should add the rest of elementsx into sset
        if (node_front != nullptr) {
			while (node_front != nullptr) {
				sset -> push_back(node_front -> value);
				node_front = node_front -> next;
			}
		}
		else {
			while (node_back != nullptr) {
				sset -> push_back(node_back -> value);
				node_back = node_back -> next;
			}
		}
    }
    return *sset;
}

// This function returns a SortedSet object that is the intersection of 2 SortedSet objects, 
// the left and right operands of this binary operator. 
// An intersection of 2 sets is a set of all elements that are in both sets. 
// That is, all of the values that are both in the left operand and in the right operand.
// sset1 = sset2 & sset3;

// Hint: This operator return type will be very similar to the + operator you implemented for the Distance class.


SortedSet & SortedSet::operator&(SortedSet &set){
    SortedSet* sset = new SortedSet();
    IntNode* node_front = head;
    while(node_front != nullptr){
        if(set.in(node_front->value)){
            sset->push_back(node_front->value);
        }
        node_front = node_front->next;
    }
    return *sset;
}

// This function adds the value passed in to the set. 
// It needs to make sure the value does not already exist in the set (no duplicates) 
// and that it is inserted in the proper position (in ascending order).
void SortedSet::add(int value){
    if (!in(value)){
        IntList::insert_ordered(value);
    }
}


void SortedSet::push_front(int value){
    add(value);
}

void SortedSet::push_back(int value){
    add(value);
}

// Override this function so that it does not insert duplicates.
// See specs for push_front above. The same rationale for overriding applies to this function.
void SortedSet::insert_ordered(int value){
    add(value);
}

// This function is the union-assign operator function. 
// It returns a union of the left and right operands, 
// but also sets the left operand's value to be that union as well. 
// In other words, sset1 |= sset2 is equivalent to sset1 = sset1 | sset2.

// Hint 1: Take advantage of functions you have already written and you know work.
// Hint 2: This is an assignment operator, so the return type should be the same as the assignment operator.
SortedSet & SortedSet::operator|=(SortedSet &set){
    if (set.head != nullptr) {
    SortedSet* sset = new SortedSet();
    sset = &(*this | set); //Derive the union from two sets
    
    this -> clear();
    //Assign union to the front set
    IntNode* currNode = sset -> head;
    while (currNode != nullptr) {
        this -> push_back(currNode -> value);
        currNode = currNode -> next;
    }
    
    return *sset;
	}
	else {
		return *this;
	}
}

// This function is the intersection-assign operator function. 
// It returns an intersection of the left and right operands, 
// but also sets the left operand's value to be that intersection as well. 
// In other words, sset1 &= sset2 is equivalent to sset1 = sset1 & sset2.

// Hint 1: Take advantage of functions you have already written and you know work.
// Hint 2: This is an assignment operator, so the return type should be the same as the assignment operator.
SortedSet & SortedSet::operator&=(SortedSet &set){
    SortedSet* sset = &(*this & set);
	
	this -> clear();
	
	IntNode* currNode = sset -> head;
	while (currNode != nullptr) {
		this -> push_back(currNode -> value);
		currNode = currNode -> next;
	}
	
	return *sset;
}