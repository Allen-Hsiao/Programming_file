#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void flipString(string &s){
   int resize = s.size()-1;
   char temp = ' ';
   string temp_str = " ";
   if (s.size() <= 1){
      s = s;
   }
   else{
      temp = s.back();
      temp_str = s.substr(0, resize);
      flipString(temp_str);
      s = temp + temp_str;
   }
}
// Read in input file and output file
// Read char in the input file and transfer to vector
// Reverse the vector by using recursive function 
// output the reverse char to ouput file
void rCopy(istream &input, ostream &output){
    // Read string from input file to vector.
    char ch;
    // char input_char;
    string inputstr;
    if (input.get(ch)){
        inputstr += ch;
        rCopy(input, output);
    }
    flipString(inputstr);
    output << inputstr;
}

bool rCopy(const string &inputfile, const string &outputfile){
    bool result = false;
    ifstream input;
    input.open(inputfile.c_str());
    // Verify file opened correctly.
    // Output error message and return 1 if file stream did not open correctly.
    if (!input.is_open()){
        cout << "Error opening " << inputfile << endl;
        cout << "Copy not completed" << endl;
        return false;
    }
    // Create output stream and open/create output csv file.
    ofstream output;
    output.open(outputfile.c_str());
    // Verify file opened or was created correctly.
    // Output error message and return 1 if file stream did not open correctly.
    if (!output.is_open()){
        cout << "Error opening " << outputfile << endl;
        cout << "Copy not completed" << endl;
        result = false;
    }
    else{
        rCopy(input, output);
        input.close();
        output.close();
        result = true;
    }
    return result;
}

int main (int argc, char *argv[]){
    if(argc != 3){
        cout << "Usage: " << argv[0] << "Inputfile - Outputfile" << endl;
    }
    if (rCopy(argv[1], argv[2])){ //using bool function to check if it copy or not
        cout << "Copy finish" << endl;
    }
    return 0;
}