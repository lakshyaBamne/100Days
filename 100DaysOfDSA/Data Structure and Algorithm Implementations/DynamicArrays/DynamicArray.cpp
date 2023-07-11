#include<iostream>

#include "DynamicArray.h"

using namespace std;

// default constructor
DynamicArray::DynamicArray(){
    arr = new (std::nothrow) int[1];

    if( arr == NULL ){
        // initialization failed
        cout << "__ERROR__ Initialization failed" << endl;
    }
    else{
        cout << "__LOG__ Initialization successfull" << endl;
    }
}

// this constructor asks for a value
DynamicArray::DynamicArray(int size){
    arr = new (std::nothrow) int[size];

    if( arr == NULL ){
        // initialization failed
        cout << "__ERROR__ Initialization failed" << endl;
    }
    else{
        cout << "__LOG__ Initialization successfull" << endl;
    }
}

DynamicArray::DynamicArray(int size, int initial_value){
    arr = new (std::nothrow) int[size];

    if( arr == NULL ){
        // initialization failed
        cout << "__ERROR__ Initialization failed" << endl;
    }
    else{
        cout << "__LOG__ Initialization successfull" << endl;

        // initialize all values to the given value
        for(int i=0 ; i<size ; i++){
            arr[i] = initial_value;
        }
    }


}

// overloading the array subscript operator for custom dynamic array class
int& DynamicArray::operator[](int index){
    return arr[index];
}
