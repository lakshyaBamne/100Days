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

    // number of elements actually stored in the vector by the user
    int arr_size = 0;

    // space taken by the underlying vector
    int actual_size = 0;

    // Method to resize the vector to a given size and copy existing elements
    // to the new position
    void resize(int new_size);

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

    // method to return the current size of the array
    int size();

    // method to return the total space taken by the underlying dynamic array
    int space();

    // method to add an element to the end of the existing array
    // resize the array to twice the existing size if there is no space available
    void push_back(int element);

    // method to remove the last element of the vector
    void pop_back();

    // method to add an element to the head of the array
    void push_front(int element);

    // method to pop an element from the head of the array
    void pop_front();

    // method to print general info about the array at any point
    void print_array();

    // method to insert an element at the given index in the vector
    void insert(int element, int position);

};
