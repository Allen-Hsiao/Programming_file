#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   // Create input stream and open input csv file.
   ifstream filin;
   filin.open(inputFile.c_str());
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!filin.is_open()){
      cout << "Error opening " << inputFile << endl;
      return 1;
   }
   // Read in integers from input file to vector.
   vector<int> intevet;
   int n;
   while (filin >> n){
      filin.ignore();
      intevet.push_back(n);
      
   }
   // Close input stream.
   filin.close();
   // Get integer average of all values read in.
   int sum = 0;
   int ave;
   for (unsigned i = 0; i < intevet.size(); ++i){
      sum += intevet.at(i);
   }
   ave = sum/(intevet.size());
   // Convert each value within vector to be the difference between the original value and the average.
   for (unsigned x = 0; x < intevet.size(); ++x){
      intevet.at(x) = intevet.at(x) - ave;
   }
   // Create output stream and open/create output csv file.
   ofstream filout;
   filout.open(outputFile.c_str());
   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!filout.is_open()){
      cout << "Error opening " << outputFile << endl;
      return 1;
   }
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (unsigned a = 0; a < intevet.size(); ++a){
      filout << intevet.at(a);
      if(a != intevet.size()-1){
         filout << ",";
      }
   }
   // Close output stream.
   filout.close();
   return 0;
}