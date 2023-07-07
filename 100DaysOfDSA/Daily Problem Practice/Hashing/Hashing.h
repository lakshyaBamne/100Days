#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
#include<string>

using namespace std;

class HashingProblems{
public:

    /*
        Ques-1 Two Sum

        LeetCode -> https://leetcode.com/problems/two-sum/
    */
    static vector<int> two_sum(vector<int>& nums, int target);

    /*
        Ques-2 Ransom Note

        LeetCode -> https://leetcode.com/problems/ransom-note/
    */
    static bool ransom_note(string ransomNote, string magazine);

};