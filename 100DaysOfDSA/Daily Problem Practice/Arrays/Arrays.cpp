#include "Arrays.h"

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<string>
#include<math.h>

using namespace std;

// Ques-1 Pascal's Triangle
vector<vector<int>> ArrayProblems::pascals_triangle(int num_rows){
    /*
        NOTE:-
        Revisit after learning Memoization to calculate factorial
        then use formula to find the pascal's triangle

        APPROACH:-
        Iterative Approach to find each row of the pascal's triangle using
        the row before it already stored in the triangle
    */
    vector<vector<int>> triangle;
    vector<int> temp;

    temp.push_back(1);
    triangle.push_back(temp);

    // if only one row is requested our job is complete
    if( num_rows == 1 ){
        return triangle;
    }
    else if( num_rows == 2 ){
        temp.clear();

        temp.push_back(1);
        temp.push_back(1);

        triangle.push_back(temp);

        return triangle;
    }
    else{


        for(int i=1; i<num_rows ; i++){
            temp.clear();

            // adding elements of the new row to the temp vector
            temp.push_back(1);

            for(int j=1 ; j<i ; j++){
                temp.push_back( triangle[i-1][j] + triangle[i-1][j-1] );
            }

            temp.push_back(1);
            
            // push the temporary row to the main pascal triangle
            triangle.push_back(temp);
        }

        return triangle;
    }
}

// Ques-2 Next Permutation

// utility function to reverse a given subarray in O(n)
void ArrayProblems::reverse_subarray(vector<int>& nums, int left, int right){
    while(left < right){
        swap(nums[left++], nums[right--]);
    }
}

void ArrayProblems::next_permutation(vector<int>& nums){
    /*
        NOTE:-

        This solution works fine when implemented in Python on LeetCode
        but gives overflow/segmentation fault in C++ due to the possibility of left
        being negative.

        APPROACH:-
        To find the first instance of pair from the back of the array
        where the elements are in increasing order (calling this pair breakpoint)

        -> after this breakpoint element, the array is reverse sorted

        swap the breakpoint with the first element from the back where that element
        is greater than the breakpoint
        then reverse all the remaining elements of the array right of breakpoint
    */

    int left;
    int right;

    // a single element has only 1 permutation
    if( nums.size() > 1 ){
        left = nums.size()-2;
        right = nums.size()-1;

        while( (nums[left] >= nums[right]) && (left >= 0) ){
            left--;
            right--;
        }

        if( left < 0 ){
            // the array is reverse sorted hence there is no next permutation
            reverse_subarray(nums, 0, nums.size()-1);
        }
        else{
            // now the left index store the breakpoint
            right = nums.size()-1;

            while( (right > left) && (nums[left] >= nums[right]) ){
                right--;
            }

            swap(nums[left], nums[right]);

            reverse_subarray(nums, left+1, nums.size()-1);
        }


    }


}

// Ques-3a Sort array of 0's and 1's
void ArrayProblems::sort_01(vector<int>& arr){
    /*
        NOTE:-
        Most basic Two Pointer approach problem
        easier version of the Dutch National Flag Problem

        APPROACH:-
        Maintain two pointers and make comparisons and swaps using them
    */
    int low = 0;
    int high = arr.size()-1;

    while(low < high){
        // bring the low and high pointers to 1 and 0 respectively
        while(arr[low] != 1){
            low++;
        }
        while(arr[high] != 0){
            high--;
        }

        if(low < high){
            swap(arr[low++], arr[high--]);
        }
    }

}

// Ques-3b Dutch National Flag Problem (Sort array of 0's, 1's and 2's)
void ArrayProblems::sort_012(vector<int>& arr){
    int low=0;
    int mid=0;
    int high=arr.size()-1;

    while(mid<=high){
        switch(arr[mid]){
            case 0:
                // swap with the lower value
                swap(arr[low++], arr[mid++]);

                break;
            case 1:
                // do nothing
                mid++;

                break;
            case 2:
                // swap with the higher value
                swap(arr[mid], arr[high--]);

                break;
        }
    }
}

// Ques-4 Merge Two sorted arrays in place
void ArrayProblems::merge_sorted_arrays_inplace(vector<int>& arr, int left, int mid, int right){
    /*
        NOTE:-
        Using this approach of merging two sorted lists in O(n) and in place
        we can make Merge Sort -> O(nlogn) and In-place

        APPROACH:-
        To convert a number A into B so that we can retrieve both when required in constant time

        -> Take a number greater than both A and B, say N
        -> A* <- A + N*B

        To retrieve A from A* => A* % N
        To retrieve B from A* => A* / N
    */

    // first we need to find the maximum element in the array
    int max = INT_MIN;
    // we also need the minimum value in the array to handle negative numbers
    int min = INT_MAX;

    // flag variable tells if there are any negative elements in the array
    bool negative_elements = false;

    for(int i=left ; i<=right ; i++){
        if( arr[i] > max ){
            max = arr[i];
        }
        if( arr[i] < min ){
            min = arr[i];
        }
    }

    cout << "Max value : " << max << endl;
    cout << "Min value : " << min << endl;

    max++;

    // we need to make sure that this element is non-zero
    // because we are using division and modulus operators
    if(max == 0){
        max++;
    }

    // if there are negative numbers we need to deal with them
    if( min < 0 ){
        negative_elements = true;
        min = abs(min);

        for(int i=left ; i<=right ; i++){
            arr[i] = arr[i] + min;
        }

        max = max + min;
    }

    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }

    cout << "\n";

    int left_pointer = left;
    int right_pointer = mid + 1;
    int main_pointer = left;

    // when this loop terminates, one of two pointers would have gone out of scope
    while( (left_pointer <= mid) && (right_pointer <= right) ){
        if( arr[left_pointer]%max <= arr[right_pointer]%max ){
            arr[main_pointer] = arr[main_pointer] + max*(arr[left_pointer]%max);

            main_pointer++;
            left_pointer++;
        }
        else{
            arr[main_pointer] = arr[main_pointer] + max*(arr[right_pointer]%max);

            main_pointer++;
            right_pointer++;
        }
    }

    // this loop runs if right pointer went out of range first
    while( left_pointer <= mid ){
        arr[main_pointer] = arr[main_pointer] + max*(arr[left_pointer]%max);

        main_pointer++;
        left_pointer++;
    }

    // this loop runs if left pointer went out of range first
    while( right_pointer <= right ){
        arr[main_pointer] = arr[main_pointer] + max*(arr[right_pointer]%max);

        main_pointer++;
        right_pointer++;
    }

    // at the end we should go through the array once to divide every element by max
    for(int i=left ; i<=right ; i++){
        arr[i] = arr[i] / max;
    }   

    // now we need to make all the negative numbers negative again
    
    if(negative_elements == true){
        for(int i=left ; i<=right ; i++){
            arr[i] = arr[i] - min;
        }
    }
}

// Ques-5 Majority Element (>n/2)
int ArrayProblems::majority_element(vector<int>& nums){
    /*
        NOTE:-

        APPROACH:-

        Moore Voting Algorithm - works due to assumption that a number is always in majority
    */

    int count=0;
    int candidate;

    for(int i=0 ; i<nums.size() ; i++){
        if( count == 0 ){
            candidate = nums[i];
            count++;
        }
        else{
            if( nums[i] == candidate ){
                count++;
            }
            else if( (nums[i] != candidate) && (count > 1) ){
                count--;
            }

            if( count == 0 ){
                candidate = nums[i];
                count = 0;
            }
        }

    }

    return candidate;

    
}

// ! INCOMPLETE
// Ques-6 Merge Intervals
vector<vector<int>> ArrayProblems::merge_intervals(vector<vector<int>>& intervals){
    /*
        NOTE:-

        APPROACH:-
        -> add intervals to the output array
        -> then compare the left value of the next interval to the
        right value of the last added interval to determine if merging is required
    */

    vector<vector<int>> output;

    for(auto it : intervals){
        if( output.empty() ){
            output.push_back(it);
        }
        else{
            if( output.back()[1] < it[0] ){
                // no overlap
                output.push_back(it);
            }
            else{
                output.back()[1] = max( output.back()[1], it[1] ); 
            }
        }
    }

    return output;
}

// Ques-7a Inversion Count using Merge Sort
int ArrayProblems::inversion_count_merge(vector<int>& arr, int left, int mid, int right){
    // this is the return variable
    int inversion_count_boundary = 0;
    
    vector<int> left_subarray, right_subarray;

    for(int i=left ; i<=mid ; i++){
        left_subarray.push_back(arr[i]);
    }
    for(int i=mid+1 ; i<=right ; i++){
        right_subarray.push_back(arr[i]);
    }

    int left_pointer = 0;
    int right_pointer = 0;

    int main_pointer = left;

    while( (left_pointer < left_subarray.size()) && (right_pointer < right_subarray.size())){
        if( left_subarray[left_pointer] <= right_subarray[right_pointer] ){
            arr[main_pointer] = left_subarray[left_pointer];
            left_pointer++;
            main_pointer++;
        }
        else{
            // first increase the inversion count

            inversion_count_boundary = inversion_count_boundary + (left_subarray.size() - left_pointer);

            arr[main_pointer] = right_subarray[right_pointer];
            main_pointer++;
            right_pointer++;
        }
    }

    if( left_pointer < left_subarray.size() ){
        while( left_pointer < left_subarray.size() ){

            arr[main_pointer] = left_subarray[left_pointer];
            left_pointer++;
            main_pointer++;
        }
    }

    while( right_pointer < right_subarray.size() ){
        arr[main_pointer] = right_subarray[right_pointer];
        main_pointer++;
        right_pointer++;
    }

    return inversion_count_boundary;

}

int ArrayProblems::inversion_count_mergesort(vector<int>& arr, int left, int right){
    int mid = (left + right) / 2;

    if(left < right){
        return inversion_count_mergesort(arr, left, mid) + \
        inversion_count_mergesort(arr, mid+1, right) + \
        inversion_count_merge(arr, left, mid, right);
    }
    else{
        // single elements do not have any inversion
        return 0;
    }
}

// ! INCOMPLETE
// Ques-7b Inversion Count using Heap Sort
int ArrayProblems::inversion_count_heapsort(vector<int>& arr){
    return 0;
}

// ! INCOMPLETE
// Ques-7c Inversion Count BIT
int ArrayProblems::inversion_count_bit(vector<int>& arr){
    return 0;
}

// ! INCOMPLETE
// Ques-7d Inversion Count using Self-balancing Binary Search Tree
int ArrayProblems::inversion_count_bst(vector<int>& arr){
    return 0;
}


// Ques-8 Remove Duplicates
int ArrayProblems::remove_duplicates(vector<int>& nums){
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

// Ques-9 Remove Element
int ArrayProblems::remove_element(vector<int>& nums, int val){
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

// Ques-10 Summary Ranges
vector<string> ArrayProblems::summary_ranges(vector<int>& nums){
    /*
        NOTE:-
        -> we can use the to_string() method to convert an integer to string
        APPROACH:-

    */

    vector<string> output;

    if( nums.size() == 0 ){
        return output;
    }
    else if( nums.size() == 1 ){
        output.push_back( to_string(nums[0]) );
        
        return output;
    }
    
    int left = nums[0];
    int temp = nums[0];

    string string_left, string_right;

    for(int i=1 ; i<nums.size() ; i++){
        temp++;

        if( temp != nums[i] ){
            // this is a test if a single element out of range appears in start
            // or in between the list
            if( temp-1 != left ){
                string_left = to_string(left);
                string_right = to_string(temp-1);

                output.push_back( string_left + "->" + string_right );

                left = nums[i];
                temp = nums[i];
            }
            else{
                string_left = to_string(left);
                
                output.push_back(string_left);

                left = nums[i];
                temp = nums[i];
            }
        }
    }

    // at the end we need to add the last range
    if( left == temp ){
        // the last element is a single element and not a right of some range
        string_left = to_string(left);

        output.push_back(string_left);
    }
    else{
        // right is a part of some range and should be included
        string_left = to_string(left);
        string_right = to_string(temp);

        output.push_back(string_left + "->" + string_right);
    }

    return output;

}

// Ques-11 Kth largest element (without sorting) => Order Statistics

/*
    Utility function takes in a subarray and returns the position of the 
    pivot after placing it at it's correct sorted position

    -> takes the first element of the subarray as the pivot index at each iteration
*/
int ArrayProblems::get_sorted_pos(vector<int>& nums, int left, int right){
    int pivot_index = left;

    for(int i=left+1 ; i<=right ; i++){
        if( nums[i] > nums[left] ){
            swap(nums[i], nums[++pivot_index]);
        }
    }

    swap(nums[pivot_index], nums[left]);

    return pivot_index;
}

/*
    Randomized variation of the above utility function

    -> finds a random number between left and right (inclusive) and uses it as pivot
    -> replace the random pivot with the first element and apply the same procedure
*/

// Utility function to generate a random number in a range
int ArrayProblems::random_number_generator(int high, int low){
    // use srand() to generate a seed in the main function once
    // #include<cstdlib>
    // #include<time.h>
    // -> srand(time(0))

    return ( (rand() % (high-low+1)) + low );
}

int ArrayProblems::get_sorted_pos_random(vector<int>& nums, int left, int right){
    int pivot_index = random_number_generator(right, left);

    // swap left and pivot_index elements
    swap(nums[left], nums[pivot_index]);
    pivot_index = left;

    // repeat the same procedure
    for(int i=left+1 ; i<=right ; i++){
        if( nums[i] > nums[left] ){
            swap(nums[i], nums[++pivot_index]);
        }
    }

    swap(nums[pivot_index], nums[left]);

    return pivot_index;
}


int ArrayProblems::order_statistics(vector<int>& nums, int k){
    /*
        NOTE:-

        APPROACH:-

        This approach is called Order statistics and is very similar to Quick Sort
        But at the end of the algorithm the array is not sorted

        -> select any random pivot index and reorder the array in place such that
        the pivot element is at it's correct sorted position
        i.e., all elements smaller than the element are at it's left and
        all elements greater than the element are at it's right
    */

    int left = 0;
    int right = nums.size()-1;

    int pivot_position_curr;

    while(left < right){

        pivot_position_curr = get_sorted_pos_random(nums, left, right);

        if( pivot_position_curr == k-1 ){
            return nums[pivot_position_curr];
        }
        else if(pivot_position_curr < k-1){
            left = pivot_position_curr+1;
        }
        else{
            right = pivot_position_curr-1;
        }
    }

    // if control reaches here, left == right
    return nums[left];

}

/*
    Ques-12 K closest points to the origin
*/
int ArrayProblems::find_pivot_pos(vector<float>& nums, int left, int right){
    int pivot_index = ArrayProblems::random_number_generator(right, left);
    
    swap(nums[pivot_index], nums[left]);
    pivot_index = left;

    // now apply the quick select sub routine
    for(int i=left+1 ; i<=right ; i++){
        if( nums[i] < nums[left] ){
            swap(nums[++pivot_index], nums[i]);
        }
    }

    swap(nums[left], nums[pivot_index]);

    return pivot_index;
}

// function to return the kth smallest element in an array
float ArrayProblems::quick_select(vector<float>& nums, int k){
    int left = 0;
    int right = nums.size()-1;

    int pivot_index_curr;

    while( left < right ){
        cout << left << " " << right << endl;

        pivot_index_curr = ArrayProblems::find_pivot_pos(nums, left, right);

        if( pivot_index_curr == k-1 ){
            return nums[pivot_index_curr];
        }
        else if(pivot_index_curr < k-1){
            left = pivot_index_curr+1;
        }
        else{
            right = pivot_index_curr-1;
        }

    }

    // if control reaches here, left==right and that should be the answer
    return nums[left];
}

vector<vector<int>> ArrayProblems::kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> output;
    vector<float> dist;

    // initialize the distance array
    for(auto point : points){
        dist.push_back( sqrt( pow(point[0],2) + pow(point[1],2) ) );
    }

    for(auto i : dist){
        cout << i << " ";
    }

    // now find the kth smallest element in the distance array
    float limit_dist = quick_select(dist, k);

    cout << "limit_dist = " << limit_dist;

    for(auto point : points){
        if( output.size() >= k ){
            break;
        }
        else{
            if( (float)sqrt( pow(point[0],2)+pow(point[1],2) ) <= limit_dist ){
                output.push_back(point);
            }
        }
    }

    return output;
}