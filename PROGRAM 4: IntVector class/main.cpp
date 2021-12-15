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
  
  //For program_4

  //Check insert function
  cout << "Insert 6(value) at index 3" << endl;
  V1.insert(3, 6);
  cout << "Check Value at index 3(Ans should be 6): " << V1.at(3) << endl;
  cout << endl;
  
  //Check erase function
  cout << "Erase value at index 3" << endl;
  V1.erase(3);
  cout << "Check Value at index 3(Shouldn't be 6): " << V1.at(3) << endl;
  cout << endl;

  // Check push_back function
  cout << "Pushing back 10(value)" << endl;
  V1.push_back(10);
  cout << "Value at last index: " << V1.at(V1.size() - 1) << endl;
  cout << endl;

  //Check pop_back function
  cout << "Check Pop_back function" << endl;
  V1.pop_back();
  cout << "Value at last index: " << V1.at(V1.size() - 1) << endl;
  cout << endl;

  //Check clear function
  cout << "Check clear function" << endl;
  V1.clear();
  cout << "Size(Ans should be 0): " << V1.size() << endl;
  cout << endl;

  //Check resize function 
  cout << "Resizing to smaller size(2)" << endl;
  V1.resize(2, 8);
  cout << "Size(Ans should be 2): " << V1.size() << endl;
  cout << "Resizing to bigger size(20)" << endl;
  V1.resize(20, 5);
  cout << "Size(Ans should be 20): " << V1.size() << endl;
  cout << endl;

  //Check reserve function
  cout << "Check Reserve function(15)" << endl;
  V1.reserve(15);
  cout << "Size(Ans should be greater than or equal to 15): " << V1.size() << endl;
  cout << endl;

  //Check assign function
  cout << "Assigning to a smaller vector(size = 5)" << endl;
  V1.assign(5, 10);
  cout << "Size(Ans should be 5): " << V1.size() << endl;
  cout << "Value at index 2(Ans should be 10): " << V1.at(2) << endl;
  cout << "Assigning to a larger vector(size = 20)" << endl;
  V1.assign(20, 5);
  cout << "Size(Ans should be 20): " << V1.size() << endl;
  cout << "Value at index 8(Ans should be 5): " << V1.at(8) << endl;
  cout << endl;

  //Check at function   
  cout << "Value at index=5: " << V1.at(3) << endl;
  cout << endl;
  
  //Check front function
  cout << "First element: " << V1.front() << endl;
  cout << endl;
  
  //Check back function
  cout << "Last element: " << V1.back() << endl;
  cout << endl;


  return 0;
}