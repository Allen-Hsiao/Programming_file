#include <iostream>

#include "IntVector.h"

using namespace std;


int main(){
  unsigned input_capacity;
  int input_value;
  
  cout << "Enter capacity of the array: " << endl;
  cin >> input_capacity;
  
  cout << "Enter the value to be stored in the array: " << endl;
  cin >> input_value;
  
  IntVector V1(input_capacity, input_value);


  //Check size function
  cout << "Size: " << V1.size() << endl;
  cout << endl;
  
  //Check capacity function
  cout << "Capacity: " << V1.capacity() << endl;
  cout << endl;
  
  //Check empty function
  if(V1.empty()){
      cout << "IntVector is empty" << endl;
      cout << endl;
  }
  else{
      cout << "IntVector is not empty" << endl;
      cout << endl;
  }
      
  //Check at function   
  cout << "What is the value at index=2: " << V1.at(2) << endl;
  cout << endl;
  
  //Check front function
  cout << "First element: " << V1.front() << endl;
  cout << endl;
  
  //Check back function
  cout << "Last element: " << V1.back() << endl;
  cout << endl;
  
  // cout << "All values are currently " << V1.front() << " and the size is  " << V1.size() << endl;
  // cout << endl;
  





  return 0;
}