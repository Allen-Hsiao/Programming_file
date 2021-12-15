#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
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
      // cout << temp << endl;
      // cout << temp_str << endl;
      // cout << s << endl;
      flipString(temp_str);
      s = temp + temp_str;
   }
}

