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

    return 0;
}

// Ques-4 Insert Interval
vector<vector<int>> BinarySearchProblems::merge_intervals(vector<vector<int>>& intervals){
    /*
        Subroutine function required in insert interval problem
    */

    // we do not need to sort the intervals in our question
    // because the intervals array is already sorted
    // sort(intervals.begin(), intervals.end());

    vector<vector<int>> output;

    for(auto interval : intervals){
        if( output.empty() ){
            output.push_back(interval);
        }
        else{
            if( output.back()[1] >= interval[0] ){
                output.back()[1] = max(interval[1], output.back()[1]);
            }
            else{
                output.push_back(interval);
            }
        }
    }

    return output;
}

vector<vector<int>> BinarySearchProblems::insert_interval(vector<vector<int>>& intervals, vector<int>& new_interval){
    /*
        NOTE:-
        -> this question used another question on merging intervals already
        solved before

        APPROACH:-
        -> find the correct insertion position for the new interval
        by using binary search
        -> merge the intervals starting from the interval before the 
        newly placed interval

        Time complexity -> O(n)
        Space complexity -> O(1)
    */

    vector<vector<int>> output;

    int left = 0;
    int right = intervals.size()-1;

    int mid;

    while( (right-left) > 1 ){
        mid = (right+left)/2;

        if( intervals[mid][0] == new_interval[0] ){
            // exact index for the new insertion is found
            break;
        }
        else if( intervals[mid][0] > new_interval[0] ){
            right = mid;
        }
        else{
            left = mid;
        }
    }

    for(int i=0 ; i<=mid ; i++){
        output.push_back(intervals[i]);
    }

    output.push_back(new_interval);

    for(int i=mid+1 ; i<intervals.size() ; i++){
        output.push_back(intervals[i]);
    }

    // now merge intervals of the new array
    output = merge_intervals(output);

    return output;

}