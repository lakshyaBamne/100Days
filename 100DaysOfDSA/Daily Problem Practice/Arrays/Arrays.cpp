#include "Arrays.h"

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

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