#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string file_name, char cha);


int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt(string file_name, char cha){
   ifstream filin;
   string line;
   char ch;
   filin.open(file_name.c_str());
   int numChar = 0;

   if (!filin.is_open()){
      cout << "Error opening " << file_name << endl;
      exit(1);
   }

   while (filin.get(ch)){
      if (ch == cha){
         numChar++;
      }
   }
   filin.close();
   return numChar;
}
