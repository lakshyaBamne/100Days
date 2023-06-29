#include "misc.h"

#include<iostream>
#include<vector>
#include<utility>
#include<math.h>

using namespace std;

// Array/String - Easy
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
