// main module to run and check all the implementations
#include<iostream>
#include<vector>

#include "Heap.h"

using namespace std;

int main(){
    // vector which is used to test all the operations
    vector<int> arr = {16,10,3,4,5,6,7,8,9};

    MinHeap::build_min_heap(arr);

    cout << "Min Heap : ";
    for(auto i : arr){
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}