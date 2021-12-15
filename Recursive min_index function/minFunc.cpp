#include <iostream>
#include "minFunc.h"

using namespace std;
const int * min(const int arr[], int arrSize) {
    if (arrSize == 1){
        return arr;
    }
    else if(arrSize < 1){
        return nullptr;
    }
    const int *smallest_value = min(arr + 1, arrSize - 1);
    if (*smallest_value < *arr){
        return smallest_value;
    }
    else{
        return arr;
    }
}