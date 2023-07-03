#include "BinarySearch.h"

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

// Ques-1 GIF of Square root of x
int BinarySearchProblems::sqrt(int x){
    /*
        NOTE:-

        APPROACH:-
        Binary Search approach to find the Square root of a number
        -> can be extended to find any nth root of the number
    */
    if(x < 3){
        return 1;
    }

    int left_limit = 1;
    int right_limit = (x/2)+1;

    long long int mid;

    while( left_limit < right_limit-1 ){
        mid = (left_limit + right_limit) / 2;

        if( mid*mid <= x ){
            left_limit = mid;
        }  
        else{
            right_limit = mid;
        }
    }

    return left_limit;
}

// Ques-2 Check if array is sorted and rotated

// utility function to find the minimum element and it's index in an array
pair<int,int> BinarySearchProblems::find_min(vector<int>& nums){
    pair<int,int> min_pair;

    min_pair.first = nums[0];
    min_pair.second = 0;

    // a single element is itself the smallest element
    if( nums.size() == 1 ){
        return min_pair;
    }

    for(int i=1 ; i<nums.size() ; i++){
        if( nums[i] < min_pair.first ){
            min_pair.first = nums[i];
            min_pair.second = i;
        }
    }

    return min_pair;
}

// utility function to check if a given sub array is increasing or not
bool BinarySearchProblems::is_increasing(vector<int>& nums, int left, int right){

}

bool BinarySearchProblems::check_sorted_and_rotated(vector<int>& nums){
    /*
        NOTE:-

        APPROACH:-

        1) count the number of adjacent inversions which is 1 in case of 
        sorted and rotated arrays

    */

    // min.first -> smallest element
    // min.second -> index of the smallest element
    pair<int,int> min = find_min(nums);

}

// Ques-3 Search in a rotated array
int BinarySearchProblems::search_rotated(vector<int>& nums, int target){
    /*
        NOTE:-

        APPROACH:-

    */

    
}