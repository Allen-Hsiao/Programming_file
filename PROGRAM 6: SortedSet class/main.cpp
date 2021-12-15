#include <iostream>
#include "SortedSet.h"
#include "IntList.h"

using namespace std;

int main(){
    SortedSet sset1;
    SortedSet sset2;
    SortedSet sset3;
    cout << "Check push_back function: Assign 0 to 9 to sset1" << endl;
    for (unsigned i = 0; i < 10; ++i){
        sset1.push_back(i);
    }
    cout << sset1 << endl;

    cout << "Check push_back function: Assign 5 to 9 to sset2" << endl;
    for (unsigned i = 5; i < 10; ++i){
        sset2.push_back(i);
    }
    cout << sset2 << endl;

    cout << "Check push_front function: Assign 20 to sset2" << endl;
    sset2.push_front(20);
    cout << sset2 << endl;

    cout << "Check add function: Add 100 to sset2" << endl;
    sset2.add(100);
    cout << sset2 << endl;

    cout << "Check insert_order function: Insert 50 to sset2" << endl;
    sset2.insert_ordered(50);
    cout << sset2 << endl;

    cout << "Check in function: Check if 100 exist in sset2" << endl;
    cout << sset2 << endl;
    cout << sset2.in(100) << "1 for true" << endl;

    cout << "Check operator| function: Derive the union of sset1 and sset2" << endl;
    cout << "sset1: " << sset1 << endl;
    cout << "sset2: " << sset2 << endl;
    cout << "The union will be: " << (sset1 | sset2) << endl;

    cout << "Check operator& function: Derive the intersection of sset1 and sset2" << endl;
    cout << "sset1: " << sset1 << endl;
    cout << "sset2: " << sset2 << endl;
    cout << "The intersection will be: " << (sset1 & sset2) << endl;

    cout << "Check operator|= function: Derive the union of sset1 and sset2 and assign value to sset1" << endl;
    cout << "sset1: " << sset1 << endl;
    cout << "sset2: " << sset2 << endl;
    (sset1 |= sset2);
    cout << "sset1 will be(Union of sset1 and sset2): " << sset1 << endl;

    cout << "Check operator&= function: Derive the intersection of sset1 and sset2 and assign value to sset1" << endl;
    cout << "sset1: " << sset1 << endl;
    cout << "sset2: " << sset2 << endl;
    (sset1 &= sset2);
    cout << "sset1 will be(intersection of sset1 and sset2): " << sset1 << endl;

    return 0;
}