/*
    Striver SDE Sheet link -> https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/
*/

#pragma once

#include<iostream>
#include<vector>
#include<utility>
#include<math.h>

using namespace std;

// class encapsulates all the solutions of Striver SDE Questions sheet
// this class can be imported to any other .cpp file later to test the solutions
class StriverSde{
public:    
    /*
        Ques-1 Set Matrix Zeroes

        LeetCode -> https://leetcode.com/problems/set-matrix-zeroes/
        CodingNinjas -> https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
    */
    static void set_matrix_zeroes(vector<vector<int>>& matrix);

    /*
        Ques-2 Pascal's Triangle

        LeetCode -> https://leetcode.com/problems/pascals-triangle/
        CodingNinjas -> https://www.codingninjas.com/codestudio/problems/1089580?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
    */
    static vector<vector<int>> pascals_triangle(int num_rows);

    /*
        Ques-3 Next Permutation

        LeetCode -> https://leetcode.com/problems/next-permutation/
        CodingNinjas -> https://www.codingninjas.com/studio/problems/893046?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
    */
    // one utility function is required for this problem to reverse a subarray efficiently
    static void reverse_subarray(vector<int>& nums, int left, int right);
    static void next_permutation(vector<int>& nums);

    /*
        Ques-4a Sort an array of 0's and 1's

        GeeksForGeeks -> https://practice.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
    */
    static void sort_01(vector<int>& arr);

    /*
        Ques-4b Dutch National Flag Problem (Sort an array of 0's, 1's and 2's)

        LeetCode -> https://leetcode.com/problems/sort-colors/
        CodingNinjas -> 
    */
    static void sort_012(vector<int>& arr);

    /*
        Ques-5 Merge Sorted Arrays

        LeetCode -> https://leetcode.com/problems/merge-sorted-array/
    */
    static void merge_sorted_arrays_inplace(vector<int>& arr, int left, int mid, int right);

    /*
        Ques-6 Rotate Image

        LeetCode -> https://leetcode.com/problems/rotate-image/
    */
    static void rotate_image(vector<vector<int>>& matrix);

    /*
        Ques-7 Merge Intervals

        LeetCode -> https://leetcode.com/problems/merge-intervals/
    */
    static vector<vector<int>> merge_intervals(vector<vector<int>>& intervals);

    /*
        Ques-8 GIF of Square Root of x

        LeetCode -> https://leetcode.com/problems/sqrtx/
    */
    static int sqrt(int x);

    /*
        Ques-9 Inversion Count of an Array

        GeeksForGeeks -> https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
    */

    // 9a: Using Merge Sort
    static int inversion_count_merge(vector<int>& arr, int left, int mid, int right);
    static int inversion_count_mergesort(vector<int>& arr, int left, int right);

    // ! INCOMPLETE
    // 9b: Using Heap Sort 
    static int inversion_count_heapsort(vector<int>& arr);

    // ! INCOMPLETE
    // 9c: Using BIT
    static int inversion_count_bit(vector<int>& arr);

    // 9d: Using Self-balancing Binary Search Tree
    static int inversion_count_bst(vector<int>& arr);

    /*
        Ques-10 Valid Palindrome

        LeetCode -> https://leetcode.com/problems/valid-palindrome/
    */

};
