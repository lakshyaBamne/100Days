/*
    Implementation of all the operations on a Heap
*/
#include "Heap.h"

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

//! MinHeap class
void MinHeap::min_heapify(vector<int>& arr, int parent){
    // first we should find if the size of the array is Even or Odd
    // -> Even : Last parent will have 1 children
    // -> Odd : Last parent will have 2 children

    /*
        In any case, for a 0-based array, the last parent has the same index 

        -> (N-2)/2 {where N is the size of the array}
    */

    int left_child, right_child;
    int min_index;

    if( (parent*2 + 2) < arr.size() ){
        // both children exists
        left_child = parent*2 + 1;
        right_child = parent*2 + 2;

        min_index = ( arr[left_child] == min(arr[left_child], arr[right_child])  ) ? left_child : right_child;

        if( arr[min_index] < arr[parent] ){
            swap(arr[parent], arr[min_index]);

            // then call the same function on the swapped element
            min_heapify(arr, min_index);
        }

    }    
    else if( (parent*2 + 2) == arr.size() ){
        // only one child exists
        min_index = parent*2 + 1;

        if( arr[min_index] < arr[parent] ){
            swap(arr[parent], arr[min_index]);

            min_heapify(arr, min_index);
        }

    }
    else{
        // no child exists so do nothing

    }
    
}


void MinHeap::build_min_heap(vector<int>& arr){
    int LAST_PARENT = (arr.size()-2)/2;

    for(int i=LAST_PARENT ; i>=0 ; i--){
        min_heapify(arr, i);
    }


}
