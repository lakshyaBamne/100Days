#include<iostream>
#include<vector>
#include<time.h>
#include<cstdlib>

#include "sort.h"

int main(){
    srand(time(0));

    vector<int> arr = {2,3,1,1,8,4,9,2,5,0,5};

    /* Selection Sort */
    // sort::print_vector(arr);
    // sort::selection_sort(arr);
    // sort::print_vector(arr);

    /* Insertion Sort */
    // sort::print_vector(arr);
    // sort::insertion_sort(arr);
    // sort::print_vector(arr);

    /* Bubble Sort */
    // sort::print_vector(arr);
    // sort::bubble_sort(arr);
    // sort::print_vector(arr);

    /* Merge Sort (using auziliary space) */
    // sort::print_vector(arr);
    // sort::merge_sort(arr, 0, arr.size()-1);
    // sort::print_vector(arr);

    /* Inplace Merge Sort (Naive) => O(n^2 logn) */
    // sort::print_vector(arr);
    // sort::inplace_merge_sort(arr, 0, arr.size()-1);
    // sort::print_vector(arr);
    
    /* Shell Sort (Optimization over Insertion Sort) */
    // sort::print_vector(arr);
    // sort::shell_sort(arr);
    // sort::print_vector(arr);

    /* Quick Sort (Unoptimized) */
    // sort::print_vector(arr);
    // sort::quick_sort(arr, 0, arr.size()-1);
    // sort::print_vector(arr);

    /* Quick Sort (Optimized and Randomized) */
    // sort::print_vector(arr);
    // sort::randomized_quick_sort(arr, 0, arr.size()-1);
    // sort::print_vector(arr);

    return 0;
}