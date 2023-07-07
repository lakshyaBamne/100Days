#include "Hashing.h"

#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
#include<string>

using namespace std;

// Ques-1 Two Sum
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

// Ques-2 Ransom Note
bool HashingProblems::ransom_note(string ransomNote, string magazine){
    unordered_map<char,int> umap;

    // first count the number of words given in the magazine  
    for(auto word : magazine){
        auto it = umap.find(word);

        if( it == umap.end() ){
            // word not in the map so we add it
            umap[word] = 1;
        }
        else{
            // word already present so just increment
            umap[word]++;
        }
    }

    for(int i=0 ; i<ransomNote.size() ; i++){
        auto it = umap.find(ransomNote[i]);

        if( it == umap.end() ){
            // word is not present in the magazine umap
            return false;
        }
        else{
            if( umap[ransomNote[i]] < 1 ){
                return false;
            }
            else{
                umap[ransomNote[i]]--;
            }
        }
    }

    // now decrease count one by one for chars in ransom note
    return true;
}
