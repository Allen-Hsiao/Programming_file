#include <iostream>
#include <vector>
#include <stdexcept>

#include "IntVector.h"

using namespace std;

IntVector::IntVector(){
    _size = 0;
    _capacity = 0;
    _data = 0;
}

IntVector::IntVector(int size){
    _size = size;
    _capacity = size;
    _data = new int[_size];
}
IntVector::IntVector(unsigned capacity, int value){
    _size = capacity;
    _capacity = capacity;
    if (_capacity > 0){
        _data = new int[_size];
    }
    for (unsigned i = 0; i < _size; i++) {
        _data[i] = value;    //initializes array to given size
    }
}

IntVector::~IntVector(){
    delete [] _data;
}

unsigned IntVector::size() const{
    return _size;
}
unsigned IntVector::capacity() const{
    return _capacity;
}

bool IntVector::empty() const{
    bool result = false;
    if (_size == 0){
        result = true;
    }
    return result;
}

const int & IntVector::at(unsigned index) const{
    if (index >= _size){
        throw out_of_range("IntVector::at_range_check");
        exit(1);
    }
    return _data[index];
    exit(1);
}

const int & IntVector::front() const{
    return _data[0];
    exit(1);
}

const int & IntVector::back() const{
    return _data[_size-1];
    exit(1);
}