/*
    Definition of a class that defines all the operations on a Heap
*/
#pragma once

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

class MinHeap{
public:
    // min_heapify is used to correct the conflict at a single node
    static void min_heapify(vector<int>& arr, int parent);

    // build min heap is used to build a min-heap from any unordered array
    static void build_min_heap(vector<int>& arr);



};

class MaxHeap{

};



