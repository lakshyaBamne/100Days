/*
    Definition of a class that defines all the operations on a Heap
*/
#pragma once

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

class heap{
public:

//! UTILITY FUNCTIONS

//! HEAP OPERATIONS
    // heapify operations => both take O(logN)
    static void max_heapify(vector<int>& arr);
    
    static void min_heapify(vector<int>& arr);

};



