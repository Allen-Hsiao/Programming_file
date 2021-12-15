#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readData(const string &inputFile, vector<double> &angle, vector<double> &coefficient){
    ifstream filin;
    filin.open(inputFile.c_str());

    if (!filin.is_open()){
      cout << "Error opening " << inputFile << endl;
      exit(1);
   }

    double n,m;

    while (filin >> n){
      filin.ignore();
      angle.push_back(n);
      filin >> m;
      coefficient.push_back(m);

   }

}
double interpolation(double b, const vector<double> &angle, const vector<double> &coefficient){
    double result;
    double a;
    double c;
    double f_a;
    double f_c;
    vector<double>lowernum;
    for (unsigned i = 0; i < angle.size(); ++i){
        if (b >= angle.at(i)){
            lowernum.push_back(angle.at(i));
        }
    }
    a = lowernum.at(lowernum.size()-1);

    vector<double>uppernum;
    for (unsigned i = 0; i < angle.size(); ++i){
        if (b <= angle.at(i)){
            uppernum.push_back(angle.at(i));
        }
    }
    c = uppernum.at(0);


    for (unsigned i = 0; i < angle.size(); ++i){
        if (a == angle.at(i)){
            f_a = coefficient.at(i);
        }
    }
    for (unsigned i = 0; i < angle.size(); ++i){
        if (c == angle.at(i)){
            f_c = coefficient.at(i);
        }
    }
   if(a == c){
      result = f_a;
   }
   else{
      result = f_a + ((b - a)/(c - a))*(f_c - f_a);
   }    

    // f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))
    // y = y0 + ((y1 - y0)/(x1 - x0)) * (x - x0)
    return result;
    
}
bool isOrdered(const vector<double> &angle){
    bool result = false;
    unsigned count = 0;
    unsigned count_equal = 0;
    if (angle.size() <= 1){
        result = true;
    }
    else{
        for (unsigned i = 0; i < angle.size()-1; ++i){
            if (angle.at(i) < angle.at(i+1)){
                count += 1;
            }
        }
        for (unsigned i = 0; i < angle.size()-1; ++i){
            if (angle.at(i) == angle.at(i+1)){
                count_equal += 1;
            }
        }

        if (count == (angle.size()-1) || count_equal == (angle.size()-1)){
            result = true;
        }
    }
    return result;
}
void reorder(vector<double> &angle, vector<double> &coefficient){
    int indexSmallest;
    double temp;
    double temp_1;
    if (angle.size() > 0){
        for (unsigned i = 0; i < angle.size() - 1; ++i) {
            // Find index of smallest remaining element
            indexSmallest = i;
            for (unsigned j = i + 1; j < angle.size(); ++j) {
                if (angle.at(j) < angle.at(indexSmallest)) {
                    indexSmallest = j;
                }
            }
        
            // Swap numbers[i] and numbers[indexSmallest]
            temp = angle.at(i);
            temp_1 = coefficient.at(i);
            angle.at(i) = angle.at(indexSmallest);
            coefficient.at(i) = coefficient.at(indexSmallest);
            angle.at(indexSmallest) = temp;
            coefficient.at(indexSmallest) = temp_1;
        }
    }
    
}



int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];


   //Create two vector
   vector<double> angle;
   vector<double> coefficient;

   //store data from input file
   readData(inputFile, angle, coefficient);

   //Ask user to input angle & output the corresponding coefficient
   double input_angle;
   double output_coefficient;
   cout << "Input angle: " << endl;
   cin >> input_angle;
   if (isOrdered(angle) == false){
       reorder(angle, coefficient);
   }
   reorder(angle,coefficient);
   output_coefficient = interpolation(input_angle, angle, coefficient);
   cout << output_coefficient << endl;

   string userinput;
   cout << "Do you want to enter another angle?" << endl;
   cin >> userinput;
   while(true){
       if (userinput == "Yes"){
           cout << "Input angle: " << endl;
           cin >> input_angle;
           output_coefficient = interpolation(input_angle, angle, coefficient);
           cout << output_coefficient << endl;
        if (userinput == "No")
        {
            break;
        }
       }
        
    return 0;

   }
}


