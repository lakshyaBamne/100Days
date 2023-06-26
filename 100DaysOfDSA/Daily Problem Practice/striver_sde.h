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
        Ques-4 Kadane's Algorithm (Maximum Subarray problem)

        LeetCode -> https://leetcode.com/problems/maximum-subarray/
        CodingNinjas ->
    */
    static int maximum_subarray(vector<int>& nums);

    /*
        Ques-5a Sort an array of 0's and 1's

        GeeksForGeeks -> https://practice.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
    */
    static void sort_01(vector<int>& arr);

    /*
        Ques-5b Dutch National Flag Problem (Sort an array of 0's, 1's and 2's)

        LeetCode -> https://leetcode.com/problems/sort-colors/
        CodingNinjas -> 
    */
    static void sort_012(vector<int>& arr);

    /*
        Ques-6 Stock Buy and Sell

        LeetCode -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
        CodingNinjas -> https://www.codingninjas.com/studio/problems/893405?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
    */
    static int best_time_to_buy_sell_stock(vector<int>& prices);

};
