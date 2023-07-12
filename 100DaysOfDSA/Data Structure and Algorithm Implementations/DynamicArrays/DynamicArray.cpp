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
        actual_size = 1;

        cout << "__LOG__ Initialization successfull" << endl;
    }
}

// parameterized constructor-1
DynamicArray::DynamicArray(int size){
    arr = new (std::nothrow) int[size];

    if( arr == NULL ){
        // initialization failed
        cout << "__ERROR__ Initialization failed" << endl;
    }
    else{
        cout << "__LOG__ Initialization successfull" << endl;

        actual_size = size;
    }
}

// parameterized constructor-2
DynamicArray::DynamicArray(int size, int initial_value){
    arr = new (std::nothrow) int[size];

    if( arr == NULL ){
        // initialization failed
        cout << "__ERROR__ Initialization failed" << endl;
    }
    else{
        cout << "__LOG__ Initialization successfull" << endl;

        arr_size = size;
        actual_size = size;

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

// return the size of the elements
int DynamicArray::size(){
    return arr_size;
}

// return the space taken by the underlying array
int DynamicArray::space(){
    return actual_size;
}

// resize the array to a given size and copy existing elements
void DynamicArray::resize(int new_size){
    actual_size = actual_size*2;


    // create a new dynamic array with the given size
    int* temp = new (std::nothrow) int[new_size];

    for(int i=0 ; i<min(arr_size, new_size) ; i++){
        temp[i] = arr[i];
    }

    // after copying the elements to new location, delete the old array
    delete [] arr;

    // now pass the location of the new elements to the original pointer
    arr = temp;
}

// add an element to the back of the array
void DynamicArray::push_back(int element){
    if(arr_size < actual_size){
        // there is space in the underlying array for the addition
        arr[arr_size++] = element;
    }
    else{
        resize(actual_size*2);
        arr[arr_size++] = element;
    }
}

// remove an element from the back of the array
void DynamicArray::pop_back(){
    if( arr_size <= 0 ){
        cout << "__ERROR__ Cannot remove from an empty array!" << endl;
    }
    else{
        // just make the size of the array smaller
        arr_size--;
    }
}

// add an element to the front of the array
void DynamicArray::push_front(int element){
    if( arr_size == actual_size ){
        resize(actual_size*2);

        actual_size = actual_size*2;

        // now copy all elements to the next index and insert new at index=0
        for(int i=arr_size-1 ; i>=0 ; i--){
            arr[i+1] = arr[i];
        }

        arr[0] = element;
    }
    else{
        // now copy all elements to the next index and insert new at index=0
        for(int i=arr_size-1 ; i>=0 ; i--){
            arr[i+1] = arr[i];
        }

        arr[0] = element;
    }
}

// remove an element from the front of the array
void DynamicArray::pop_front(){
    if( arr_size == 1 ){
        // array should become empty
        arr_size = 0;
    }
    else{
        // point the head of the array to the first element
        arr = arr+1;

        // also decrease the size of the array
        arr_size--;
        actual_size--;
    }
    
}

// method to add an element to the given position
void DynamicArray::insert(int element, int position){
    if( arr_size == actual_size ){
        resize(actual_size*2);
        actual_size = actual_size*2;

        for(int i=arr_size-1 ; i > position ; i++ ){
            arr[i+1] = arr[i];
        }

        arr[position] = element;

        arr_size++;
    }   
    else{
        for(int i=arr_size-1 ; i > position ; i++ ){
            arr[i+1] = arr[i];
        }

        arr[position] = element;

        arr_size++;
    }
}

void DynamicArray::print_array(){
    cout << "----------------------------------------------" << endl;

    cout << "Array Values : ";
    for(int i=0 ; i<arr_size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Array Size : " << arr_size << endl;
    cout << "Actual Size : " << actual_size << endl;

    cout << "----------------------------------------------" << endl;
}
