#include "misc.h"

#include<iostream>
#include<vector>
#include<utility>
#include<math.h>

using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/ 
int LeetcodeInterview150::remove_duplicates(vector<int>& nums){
    int left = 0;

    int right = 0;

    while( right < nums.size() ){
        if( nums[left] == nums[right] ){
            right++;
        }
        else{
            swap(nums[++left], nums[right++]);
        }
    }

    return ++left;
}

// https://leetcode.com/problems/remove-element/
int LeetcodeInterview150::remove_element(vector<int>& nums, int val){
    int left=0;
    int right=nums.size()-1;

    while( left <= right ){
        if( nums[left] != val ){
            left++;
        }
        else{
            swap(nums[left], nums[right--]);
        }
    }

    return left;
}

