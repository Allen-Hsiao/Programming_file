//include any standard libraries needed
#include <iostream>
#include <fstream>
using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize){
   double sum = 0;
   for (int i = 0; i < arraySize; ++i){
      sum += array[i];
   }
   return sum/arraySize;
}

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index){
   for (int i =index; i < arraySize-1; ++i){
      array[i] = array[i+1];
      }
  arraySize -= 1;
}


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize){
   for (int i =0; i < arraySize; ++i){
      if (i == arraySize-1){
         cout << array[i];
      }
      else{
         cout << array[i] << ", ";
      }
   }
}


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line
   string inputFile;
   // open file and verify it opened
   inputFile = argv[1];
   ifstream filin;
   filin.open(inputFile.c_str());
   if (!filin.is_open()){
      cout << "Error opening " << inputFile << endl;
      exit(1);
   }
   int count = 0;
   double n;
   while(filin >> n){
      count += 1;
      }
   filin.close();
   // Declare an array of doubles of size ARR_CAP.
   double aray[count];
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   // int count = 0;
   
   // if (filin.is_open()){
   //    while(filin >> n){
   //       filin >> n;
   //       filin.ignore();
   //       count += 1;
   //    }
   // }
   filin.close();

   filin.open(inputFile.c_str());  

   for (int i = 0; i < count; ++i){
      filin >> n;
      filin.ignore();
      aray[i] = n;
   }
   filin.close();
   int index_remove;
   // int size = ARR_CAP;
   // Call the mean function passing it this array and output the 
   // value returned.
   cout << "Mean: " << mean(aray, count);
   cout << endl;
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   cout << "Enter index of value to be removed (0 to "<< count-1 << "): " << endl;
   cout << endl;
	
   // Call the display function to output the array.
   cout << "Before removing value: ";
   display(aray, count);
   cout << endl;
   cout << endl;
   cin >> index_remove;
   // Call the remove function to remove the value at the index
   // provided by the user.
   remove(aray, count, index_remove);
    
   // Call the display function again to output the array
   // with the value removed.
   cout << "After removing value: ";
   display(aray, count);
   cout << endl;
   cout << endl;
   // Call the mean function again to get the new mean
 
   cout << "Mean: " << mean(aray, count);
   
	return 0;
}