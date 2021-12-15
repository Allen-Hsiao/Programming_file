#include <iostream>
#include <string>

using namespace std;

int main(){
    string name;
    char temp = ' ';
    cout << "Let's reverse your name!" << endl;
    cout << "Input your name: " << endl;
    getline(cin, name);
    for (int i = 0; i < name.size()/2; i++){
        temp = name[i];
        name[i] = name[name.size()-1-i];
        name[name.size()-1-i] = temp;
    }
    cout << name << endl;
}