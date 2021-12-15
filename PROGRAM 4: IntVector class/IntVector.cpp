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

void IntVector::expand(){
    
    if (_capacity == 0){
        _capacity = 1;
    }
    else{
        _capacity *= 2;
    }

    int* temp = new int[_capacity];
    
    for( unsigned int i = 0; i < _size; i++ ) {
        temp[i] = _data[i];
    }
    
    delete [] _data; 
    
    _data = temp;
}

void IntVector::expand(unsigned amount){
    _capacity = amount;

    int* temp = new int[_capacity];
    
    for( unsigned int i = 0; i < _size; i++ ) {
        temp[i] = _data[i];
    }
    
    delete [] _data; 
    
    _data = temp;
}

void IntVector::insert(unsigned index, int value){
    if (index > _size){
        throw out_of_range("IntVector::insert_range_check");
    }
    else if (_capacity == 0){
        expand(1);
    }
    else if (_size >= _capacity){
        expand();
    }


    _size += 1;

    for(unsigned i = _size - 1; i > index; i--){
            this->_data[i] = this->_data[i - 1];
        }
    _data[index] = value;    


}

void IntVector::erase(unsigned index){
    if(index < 0 || index >= _size)
        throw out_of_range("IntVector::erase_range_check");
        
    for(unsigned x = index; x < _size - 1; x++){
        _data[x] = _data[x + 1];
    }
    
    _size -= 1;
}

void IntVector::push_back(int value){
    if (_size >= _capacity) {
        expand();
    }
    else{

    }
    _size += 1;

    _data[_size-1] = value;
}

void IntVector::pop_back(){
    _size -= 1;
}

void IntVector::clear(){
    _size = 0;
}

void IntVector::resize(unsigned size, int value){
    if (size <= _size) {
        _size = size;
    }
    
    if (size > _size) {
        unsigned temp = _size;
        if (size > _capacity && _capacity != 0){
            expand();
        }
        if (size > _capacity){
            expand(size);
        }


        _size = size;
        for (unsigned int i = temp; i < _size; i++) {
            _data[i] = value;
        }
    }
}


void IntVector::reserve(unsigned n){
    if (n > _capacity){
        expand(n);
    }
}

void IntVector::assign(unsigned n, int value){
    if (n <= _capacity) {
        _size = n;
        for (unsigned int i = 0; i < _size; i ++) {
            _data[i] = value;
        }
    } 
    
    if (n > (2*_capacity)) {
        expand(n);
        _size = n;
        for (unsigned int i = 0; i < _size; i ++) {
            _data[i] = value;
        }
        
    }
    else if (n > _capacity){
        expand();
        _size = n;
        for (unsigned int i = 0; i < _size; i ++) {
            _data[i] = value;
        }
    }
}

int & IntVector::at(unsigned index){
    if (index >= _size){
        throw out_of_range("IntVector::at_range_check");
        exit(1);
    }
    return _data[index];
    exit(1);
}

int & IntVector::front( ){
    return _data[0];
}

int & IntVector::back( ){
    return _data[_size-1];
}
