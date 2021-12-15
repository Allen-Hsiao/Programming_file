#include <iostream>
#include "IntList.h"

using namespace std;


void IntList::distanceFrom(int key) {
   if (head != nullptr){
      head->data = searchAndModify(head, key);
   }
}

int IntList::searchAndModify(IntNode *curr, int key) {
   // Bcase1 key is equal to head
   if (key == head->data){
      return (curr->data);
   }

   // Bcase2 tail
   if (curr == nullptr){
      return 0;
   }

   // (Recursion condition) 
   if (curr != nullptr && key != curr->data){ //when curr->data == key, do nothing
      curr->data = 1 + searchAndModify(curr->next,key);
      return (curr->data);
   }
   return 0;
}

