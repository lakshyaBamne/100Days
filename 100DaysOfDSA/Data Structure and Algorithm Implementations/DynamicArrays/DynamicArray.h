/*
    Implementation of a Dynamic Array class which has all the functionality
    of STL Vector

    -> this class implements an integer vector, we can later modify it to be a class-template
    -> Underlying implementation is based on Dynamic Vectors in C++ (using new/delete keywords)
*/
#pragma once

#include<iostream> 

using namespace std;

class DynamicArray{
private:
    // underlying dynamic array should be hidden outside the class
    // this NULL pointer is given a dynamically allocated array when constructor is called
    int* arr = NULL;

public:
    // default constructor
    DynamicArray();

    // parameterized constructor-1
    DynamicArray(int size);

    // parameterized constructor-2
    DynamicArray(int size, int initial_value);

    // Operator overloading (Subscript operator [])

    // this overloaded function returns a reference
    // to the underlying array element at index
    // so that it can be directly manipulated
    int& operator[](int index);

};
