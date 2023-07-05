#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

class BinarySearchProblems{
public:
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

    /*
        Ques-4 Insert Interval

        LeetCode -> https://leetcode.com/problems/insert-interval/
    */

    // subroutine required to solve the insert interval problem
    static vector<vector<int>> merge_intervals(vector<vector<int>>& intervals);
    static vector<vector<int>> insert_interval(vector<vector<int>>& intervals, vector<int>& new_interval);

    /*
        Ques-5 Search Insert Position

        LeetCode -> https://leetcode.com/problems/search-insert-position/
    */
    static int search_insert_position(vector<int>& nums, int target);

    /*
        Ques-6 Minimum number of arrows to burst all balloons

        LeetCode -> https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
    */
    static int burst_balloons(vector<vector<int>>& points);


};