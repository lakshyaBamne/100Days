#include "Hashing.h"

#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>

using namespace std;

vector<int> HashingProblems::two_sum(vector<int>& nums, int target){
    unordered_map<int,int> umap;

    vector<int> output;

    for( int i=0 ; i<nums.size() ; i++ ){
        auto it = umap.find(nums[i]);

        if( it == umap.end() ){
            // key not found
            umap[target-nums[i]] = i;
        }
        else{
            output.push_back(it->second);
            output.push_back(i);

            return output;
        }
    }

    // if no such pair exists, an empty vector is given as output
    return output;
}