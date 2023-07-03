#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

class BinarySearchProblems{
    /*
        Ques-1 GIF of Square Root of x

        LeetCode -> https://leetcode.com/problems/sqrtx/
    */
    static int sqrt(int x);

    /*
        Ques-2 Check if an array is sorted and rotated

        LeetCode -> https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
    */
    static pair<int,int> find_min(vector<int>& nums);
    static bool is_increasing(vector<int>& nums, int left, int right);
    static bool check_sorted_and_rotated(vector<int>& nums);

    /*
        Ques-3 Search in a rotated array

        LeetCode -> https://leetcode.com/problems/search-in-rotated-sorted-array/
    */
    static int search_rotated(vector<int>& nums, int target);

};