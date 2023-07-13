#pragma once

#include<iostream>
#include<vector>

using namespace std;

class HeapProblems{
public:

    /*
        Ques-1 Make array zero by subtracting equal amounts

        LeetCode -> https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/
    */
    static void modified_min_heapify();
    static void modified_build_min_heap();

    static int minimum_operations(vector<int>& nums);
};

