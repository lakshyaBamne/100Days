/*
    Implementation of the Sorting Class 
*/

#include<iostream>
#include<vector>
#include<utility>

#include "sort.h"

using namespace std;

// Utility Function implementations
void sort::find_min(pair<int,int>& min, const vector<int>& arr, int left, int right){
    // pair.first -> minimum value in the subarray
    // pair.second -> index where the minimum value is present in the subarray

    min.first = arr[left];
    min.second = left;

    for(int i=left+1 ; i<=right ; i++){
        if(arr[i] < min.first){
            min.first = arr[i];
            min.second = i;
        }
    }
}

void sort::find_max(pair<int,int>& max, const vector<int>& arr, int left, int right){
    // pair.first -> maximum value in the subarray
    // pair.second -> index where the maximum value is present in the subarray

    max.first = arr[left];
    max.second = left;

    for(int i=left+1 ; i<=right ; i++){
        if( arr[i] > max.first ){
            max.first = arr[i];
            max.second = i;
        }
    }
}

void sort::print_vector(vector<int>& arr){
    cout << "Vector is : ";
    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Basic Sorting Algorithms

/* 
    !Selection Sort - In place stable implementation

    Time Complexity -> O(n^2)
    Space Complexity -> O(1)
*/
void sort::selection_sort(vector<int>& arr){
    pair<int, int> min;
    
    for(int i=0 ; i<arr.size() ; i++){
        // for every iteration we need the minimum value and index where it resides
        find_min(min, arr, i, arr.size()-1);

        // now we need to swap the element pointed by i with the min element
        swap(arr[i], arr[min.second]);
    }
}

/*
    !Insertion Sort - In place stable implementation

    Time Complexity -> O(n^2)
    Space Complexity -> O(1)

    => Important algorithm to sort when input is partially sorted
*/
void sort::insertion_sort(vector<int>& arr){
    // we start from the second element because a single element is always sorted
    int key, hole;

    for(int i=1 ; i<arr.size() ; i++){
        key = arr[i];
        hole = i-1;

        while( hole>=0 && arr[hole]>key ){
            arr[hole+1] = arr[hole];
            hole--;
        }

        arr[hole+1] = key;
    }
}

/*
    !Bubble Sort - In place

    Time Complexity -> O(n^2)
    Space Complexity -> O(1)
*/
void sort::bubble_sort(vector<int>& arr){
    int right = 1;

    while( arr.size() - right >= 1 ){
        for(int left=0 ; left < arr.size()-right ; left++){
            if( arr[left] > arr[left+1] ){
                swap(arr[left], arr[left+1]);
            }
        }

        right++;
    }

}


// Advanced Sorting Algorithms

/*
    !Merge Sort - Not in place but stable implementation

    => Considered best general purpose sorting algorithm with optimum time complexity

    Time Complexity -> O(nlogn)
    Space Complexity -> O(n)
*/

void sort::merge_sorted_lists(vector<int>& arr, int left, int mid, int right){
    // first create two new sub arrays in memory and copy elements to them
    vector<int> arr_left, arr_right;

    int i = left;
    while(i<=right){
        if(i<=mid){
            arr_left.push_back(arr[i]);
        }
        else{
            arr_right.push_back(arr[i]);
        }
        
        i++;
    }

    // now we should merge the two sub arrays into the original array
    int left_index=0,right_index=0, main_index=left;

    while( left_index<arr_left.size() && right_index<arr_right.size() ){
        if( arr_left[left_index] < arr_right[right_index] ){
            arr[main_index] = arr_left[left_index];
            main_index++;
            left_index++;
        }
        else{
            arr[main_index] = arr_right[right_index];
            main_index++;
            right_index++;
        }
    }

    if( left_index < arr_left.size() ){
        // right subarray was exhausted first
        while( left_index < arr_left.size() ){
            arr[main_index] = arr_left[left_index];
            left_index++;
            main_index++;
        }
    }
    else{
        // left subarray was exhausted first
        while( right_index < arr_right.size() ){
            arr[main_index] = arr_right[right_index];
            right_index++;
            main_index++;
        }
    }
}

void sort::merge_sort(vector<int>& arr, int left, int right){
    int mid;
    
    if(left < right){
        // the array has more than 1 elements
        mid = ( right + left ) / 2;

        // sorting the two subarrays recursively
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);

        // merging the two sorted lists
        merge_sorted_lists(arr, left, mid, right);
    }
}

/*
    !Merge Sort - In place implementation (to make merge sort inplace, we sacrifice the time complexity)

    Time Complexity -> varies with various inplace merging techniques
    Space Complexity -> 
*/

// this inplace merge approach is NAIVE and has time complexity => O(n^2)
void sort::inplace_merge_naive(vector<int>& arr, int left, int mid, int right){
    // pointers we need to merge two sorted lists without using extra space
    int left_pointer=left, right_pointer=mid+1, buffer;

    // buffer variable
    int key;

    while( (left_pointer<right_pointer) && (right_pointer<=right) ){
        if( arr[left_pointer] <= arr[right_pointer] ){
            // do nothing
            left_pointer++;
        }
        else{
            buffer = right_pointer;

            key = arr[buffer];

            while( buffer > left_pointer ){
                arr[buffer] = arr[buffer - 1];
                buffer--;
            }

            arr[buffer] = key;

            left_pointer = left_pointer++;
            right_pointer++;
        }
    }
}

// this in place merge approach is similar to Shell Sort has time complexity => O(nlogn)
void sort::inplace_merge_shell(vector<int>& arr, int left, int mid, int right){
    // initial gap
    int h = (left + right) / 2;

    int hole, key;

    while( h >= 1 ){
        for(int start=left ; start<h ; start++){
            for(int i=start+h ; i<=right ; i++){
                key = arr[i];
                hole = i - h;

                while( (hole>=start) && (arr[hole] > key) ){
                    arr[hole+h] = arr[hole];
                    hole = hole - h;
                }

                arr[hole+h] = key;
            }
        }

        h--;
    }

}

//! MOST OPTIMUM APPROACH
// this in place merge approach is optimum and has time complexity => O(n)
// making the overall merge sort algorihtm O(nlogn) as well as inplace
void sort::inplace_merge_optimum(vector<int>& arr, int left, int mid, int right){
    // first we need to find the maximum element in both sub arrays
    // this is done using a utility function
    int max_more = INT_MIN;

    for(int i=left ; i<=right ; i++){
        if( arr[i] > max_more ){
            max_more = arr[i];
        }
    }

    max_more++;

    cout << "max_more : " << max_more << endl;
    
    // pair<int,int> max;
    // find_max(max, arr, left, right);

    // we need a number which is strictly greater than any element in the array
    // int max_more = max.first + 1;

    // we maintain three pointers to traverse and update the smaller subarrays
    int left_pointer = left, right_pointer = mid+1, main_pointer = left;

    while( (left_pointer <= mid) && (right_pointer <= right) ){
        // first find minimum of the two values pointed by left_pointer and right_pointer
        if( arr[left_pointer]%max_more <= arr[right_pointer]%max_more ){
            arr[main_pointer] = arr[main_pointer] + (arr[left_pointer]%max_more)*max_more;
            
            main_pointer++;
            left_pointer++;
        }
        else{
            arr[main_pointer] = arr[main_pointer] + (arr[right_pointer]%max_more)*max_more;

            main_pointer++;
            right_pointer++;
        }        
    }

    // it is possible that one subarray is exhausted first, so we need to take care of the other
    while( main_pointer <= right ){
        arr[main_pointer] = arr[main_pointer] + arr[main_pointer]*max_more;
        main_pointer++;
    }


    // now divide all the elements of the array with the number max_more
    for(int i=left ; i<=right ; i++){
        arr[i] = arr[i] / max_more;
    }
}

void sort::inplace_merge_sort(vector<int>& arr, int left, int right){
    int mid;
    
    if(left < right){
        // the array has more than 1 elements
        mid = ( right + left ) / 2;

        // sorting the two subarrays recursively
        inplace_merge_sort(arr, left, mid);
        inplace_merge_sort(arr, mid+1, right);

        // merging the two sorted lists in place using various methods

        // inplace_merge_naive(arr, left, mid, right); // O(m^2)
        // inplace_merge_shell(arr, left, mid, right); // O(nlogn)
        inplace_merge_optimum(arr, left, mid, right); // O(n)
    }
}

// Other useful sorting algorithms

/* 
    !Shell Sort - an optimization over Insertion Sort

    Time Complexity => O(n^2) (for this implementation)
*/
void sort::shell_sort(vector<int>& arr){
    int h = (arr.size()-1) / 2;
    
    // temporary variables used to sort a subarray
    int hole, key;

    while( h >= 1 ){

        // we must make the array h-sorted for each value of h>=1
        for(int start=0 ; start<h ; start++){
            for( int i=start + h ; i<arr.size() ; i = i + h ){

                key = arr[i];
                hole = i - h;
                while( (hole >= start) && ( arr[hole] > key ) ){
                    arr[hole + h] = arr[hole];
                    hole = hole - h;
                }

                arr[hole + h] = key;
            }
        }

        // in this implementation we start with a gap of N/2 and reduce it by 1
        // this is not a very efficient implementation

        // other gap reductions lead to better time complexities
        // for these gap reductions refer -> https://en.wikipedia.org/wiki/Shellsort#Gap_sequences
        h--;
    }

}





