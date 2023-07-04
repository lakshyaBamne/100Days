#include<vector>
#include<utility>
#include<algorithm>
#include<string>

using namespace std;

class ArrayProblems{
public:    

    /*
        Ques-1 Pascal's Triangle

        LeetCode -> https://leetcode.com/problems/pascals-triangle/
    */
    static vector<vector<int>> pascals_triangle(int num_rows);

    /*
        Ques-2 Next Permutation

        LeetCode -> https://leetcode.com/problems/next-permutation/
    */
    // one utility function is required for this problem to reverse a subarray efficiently
    static void reverse_subarray(vector<int>& nums, int left, int right);
    static void next_permutation(vector<int>& nums);

    /*
        Ques-3a Sort an array of 0's and 1's

        GeeksForGeeks -> https://practice.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
    */
    static void sort_01(vector<int>& arr);

    /*
        Ques-3b Dutch National Flag Problem (Sort an array of 0's, 1's and 2's)

        LeetCode -> https://leetcode.com/problems/sort-colors/
    */
    static void sort_012(vector<int>& arr);

    /*
        Ques-4 Merge Sorted Arrays

        LeetCode -> https://leetcode.com/problems/merge-sorted-array/
    */
    static void merge_sorted_arrays_inplace(vector<int>& arr, int left, int mid, int right);

    /*
        Ques-5 Majority Element

        LeetCode -> https://leetcode.com/problems/majority-element/
    */
    static int majority_element(vector<int>& nums);

    /*
        Ques-6 Merge Intervals

        LeetCode -> https://leetcode.com/problems/merge-intervals/
    */
    static vector<vector<int>> merge_intervals(vector<vector<int>>& intervals);

    /*
        Ques-7 Inversion Count of an Array

        GeeksForGeeks -> https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
    */

    // 7a: Using Merge Sort
    static int inversion_count_merge(vector<int>& arr, int left, int mid, int right);
    static int inversion_count_mergesort(vector<int>& arr, int left, int right);

    // ! INCOMPLETE
    // 7b: Using Heap Sort 
    static int inversion_count_heapsort(vector<int>& arr);

    // ! INCOMPLETE
    // 7c: Using BIT
    static int inversion_count_bit(vector<int>& arr);

    // ! INCOMPLETE
    // 7d: Using Self-balancing Binary Search Tree
    static int inversion_count_bst(vector<int>& arr);

    /*
        Ques-8 Remove Duplicates

        LeetCode -> https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    */
    static int remove_duplicates(vector<int>& nums);

    /*
        Ques-9 Remove Element

        LeetCode -> https://leetcode.com/problems/remove-element/ 
    */
    static int remove_element(vector<int>& nums, int val);

    /*
        Ques-10 Summary Ranges

        LeetCode -> https://leetcode.com/problems/summary-ranges/
    */
    static vector<string> summary_ranges(vector<int>& nums);

    
};

