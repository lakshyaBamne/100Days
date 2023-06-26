/*
    Implementations of the functions acting as solutions for the
    Striver SDE sheet
*/

#include "striver_sde.h"

#include<iostream>
#include<vector>
#include<utility>
#include<math.h>

using namespace std;

// Ques-1 Set Matrix Zeroes
void StriverSde::set_matrix_zeroes(vector<vector<int>>& matrix){
    /*
        NOTE:-
        Time complexity cannot be optimized below O(mn)
        because we need to access and check every element in the mxn matrix

        APPROACH:-
        We store the information about which row and column to make zero
        in the first row and column of the matrix itself
    */

    // first column in completely used to store the row information
    // thus one extra variable is needed to store information about the first index of column
    int col0=1;

    // if there is a 0 in the first column
    for(int i=0 ; i<matrix[0].size() ; i++){
        if( matrix[0][i] == 0 ){
            col0 = 0;
        }
    }

    // if there is a 0 in the first row
    for(int i=0 ; i<matrix.size() ; i++){
        if( matrix[i][0] == 0 ){
            matrix[0][0] = 0;
        }
    }

    // all the other elements
    for(int i=1 ; i<matrix.size(); i++){
        for(int j=1 ; j<matrix[0].size() ; j++){
            if( matrix[i][j] == 0 ){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // now we start making the rows and columns zero using the acquired information
    // start by changing only the elements in the matrix without first row and column
    for(int i=1 ; i<matrix.size() ; i++){
        if( matrix[i][0] == 0 ){
            for(int j=1 ; j<matrix[0].size() ; j++){
                matrix[i][j] = 0;
            }
        }
    }

    for(int i=1 ; i<matrix[0].size() ; i++){
        if( matrix[0][i] == 0 ){
            for(int j=1 ; j<matrix.size() ; j++){
                matrix[j][i] = 0;
            }
        }
    }

    // now we need to change the first row and column based on values of extra variable
    if( matrix[0][0]==0 && col0==0 ){
        // both first row and column must be entirely zero
        for(int i=0 ; i<matrix.size() ; i++){
            matrix[i][0] = 0;
        }
        for(int i=0 ; i<matrix[0].size() ; i++){
            matrix[0][i] = 0;
        }
    }
    else if( matrix[0][0]==0 && col0!=0 ){
        for(int i=0 ; i<matrix.size() ; i++){
            matrix[i][0] = 0;
        }
    }
    else if( matrix[0][0]!=0 && col0==0 ){
        for(int i=0 ; i<matrix[0].size() ; i++){
            matrix[0][i] = 0;
        }
    }
}

// Ques-2 Pascal's Triangle
vector<vector<int>> StriverSde::pascals_triangle(int num_rows){
    /*
        NOTE:-
        Revisit after learning Memoization to calculate factorial
        then use formula to find the pascal's triangle

        APPROACH:-
        Iterative Approach to find each row of the pascal's triangle using
        the row before it already stored in the triangle
    */
    vector<vector<int>> triangle;
    vector<int> temp;

    temp.push_back(1);
    triangle.push_back(temp);

    // if only one row is requested our job is complete
    if( num_rows == 1 ){
        return triangle;
    }
    else if( num_rows == 2 ){
        temp.clear();

        temp.push_back(1);
        temp.push_back(1);

        triangle.push_back(temp);

        return triangle;
    }
    else{


        for(int i=1; i<num_rows ; i++){
            temp.clear();

            // adding elements of the new row to the temp vector
            temp.push_back(1);

            for(int j=1 ; j<i ; j++){
                temp.push_back( triangle[i-1][j] + triangle[i-1][j-1] );
            }

            temp.push_back(1);
            
            // push the temporary row to the main pascal triangle
            triangle.push_back(temp);
        }

        return triangle;
    }
}

// Ques-3 Next Permutation

// utility function to reverse a given subarray in O(n)
void StriverSde::reverse_subarray(vector<int>& nums, int left, int right){
    while(left < right){
        swap(nums[left++], nums[right--]);
    }
}

void StriverSde::next_permutation(vector<int>& nums){
    /*
        NOTE:-

        APPROACH:-
        To find the first instance of pair from the back of the array
        where the elements are in increasing order (calling this pair breakpoint)

        -> after this breakpoint element, the array is reverse sorted

        swap the breakpoint with the first element from the back where that element
        is greater than the breakpoint
        then reverse all the remaining elements of the array right of breakpoint
    */

    int bp, bp_temp;

    if( nums.size() > 1 ){
        bp = nums.size()-2;
        bp_temp = nums.size()-1;
        
        // find breakpoint
        while( (nums[bp]>=nums[bp_temp]) && (bp>=0) ){
            bp--;
            bp_temp--;
        }

        if( bp<0 ){
            reverse_subarray(nums, 0, nums.size()-1);
        }
        else{
            bp_temp = nums.size()-1;

            while( (nums[bp]>=nums[bp_temp]) && (bp_temp>bp+1) ){
                bp_temp--;
            }

            swap(nums[bp], nums[bp_temp]);

            reverse_subarray(nums, bp+1, nums.size()-1);
        }
    }
}

// Ques-4 Kadane's Algorithm (Maximum Subarray problem)
int StriverSde::maximum_subarray(vector<int>& nums){
    /*
        NOTE:-
        Dynamic Programming Approach

        APPROACH:-

    */
}

// Ques-5a Sort array of 0's and 1's
void StriverSde::sort_01(vector<int>& arr){
    /*
        NOTE:-
        Most basic Two Pointer approach problem
        easier version of the Dutch National Flag Problem

        APPROACH:-
        Maintain two pointers and make comparisons and swaps using them
    */
    int low = 0;
    int high = arr.size()-1;

    while(low < high){
        // bring the low and high pointers to 1 and 0 respectively
        while(arr[low] != 1){
            low++;
        }
        while(arr[high] != 0){
            high--;
        }

        if(low < high){
            swap(arr[low++], arr[high--]);
        }
    }

}

// Ques-5b Dutch National Flag Problem (Sort array of 0's, 1's and 2's)
void StriverSde::sort_012(vector<int>& arr){
    int low=0;
    int mid=0;
    int high=arr.size()-1;

    while(mid<=high){
        switch(arr[mid]){
            case 0:
                // swap with the lower value
                swap(arr[low++], arr[mid++]);

                break;
            case 1:
                // do nothing
                mid++;

                break;
            case 2:
                // swap with the higher value
                swap(arr[mid], arr[high--]);

                break;
        }
    }
}

// Ques-6 Stock Buy and Sell
int StriverSde::best_time_to_buy_sell_stock(vector<int>& arr){
    /*
        NOTE:-
        Dynamic Programming Approach

        APPROACH:-

    */


}

