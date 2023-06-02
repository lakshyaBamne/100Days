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

void sort::print_vector(vector<int>& arr){
    cout << "Vector is : ";
    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Basic Sorting Algorithms

/* 
    Selection Sort - In place stable implementation

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
    Insertion Sort - In place stable implementation

    Time Complexity -> O(n^2)
    Space Complexity -> O(1)
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
    Bubble Sort - In place

    Time Complexity -> 
    Space Complexity -> 
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

