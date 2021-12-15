#include <iostream>
#include <vector>
#include "IntList.h"

using namespace std;

IntList::IntList(){
    head = NULL;
    tail = NULL;
}

IntList::IntList(const IntList &cpy) {
	head = nullptr;
	tail = nullptr;
	IntNode* currNode = cpy.head;
	while (currNode != nullptr) {
		push_back(currNode -> value);
		currNode = currNode -> next;
	}
}

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

IntList::~IntList(){
    IntNode* temp;
    
    while(head != NULL) {     
        temp = head; 
        head = head -> next;
        delete temp;
	}
}

const int & IntList::front() const{
    return head->value;
}

const int & IntList::back() const{
    return tail->value;
}

bool IntList::empty() const{
    if (head == NULL){ //Only need to check if head have value since tail can be head
        return true;
    }
    return false;
}

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

void IntList::pop_front(){
    if (head != NULL && tail != NULL){
        IntNode*temp = head->next; //reconnect the head to the next node
        delete head;
        head = temp;
    }
}

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

IntNode * IntList::min(IntNode *){
    return nullptr;
}

void copy(const IntList &){

}