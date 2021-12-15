#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

/* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */
ostream & operator<<(ostream &out, const IntList &rhs){
   if (rhs.head == 0){
      return out;
   }
   operator<<(out, rhs.head);
   return out;
}

/* Returns true if the integer passed in is contained within the IntList.
   Otherwise returns false.
*/
bool IntList::exists(int val) const{
   bool result = false;
   if (head == nullptr){
      result = false;
      return result;
   }
   if (val == head->value){
      result = true;
      return result;
   }
   return exists(head->next, val);
}

/* Helper function that returns true if the integer passed in is contained within
   the IntNodes starting from the IntNode whose address is passed in.
   Otherwise returns false.
*/
bool IntList::exists(IntNode *node, int val) const{
   if (node == nullptr){
      return false;
   }
   if (node -> value == val){
      return true;
   }
   return exists(node->next, val);
}

/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream & operator<<(ostream &out, IntNode *rhs){
   if (rhs == nullptr){
      return out;
   }
   out << rhs->value;
   if (rhs->next != nullptr){
      out << " ";
   }
   operator<<(out, rhs->next);
   return out;
}