/*
    Definition of the Sorting Class
*/
#pragma once

#include<iostream>
#include<vector>
#include<utility> // module for using pairs in functions
#include<cstdlib> // module for random number generation

using namespace std;

class sort{
public:
    //! UTILITY FUNCTIONS
    // function to find the minimum element from a given sub array
    static void find_min(pair<int,int>& min, const vector<int>& arr, int left, int right);

    static void find_max(pair<int,int>& max, const vector<int>& arr, int left, int right);
    
    // function to print a vector at any given point in time
    static void print_vector(vector<int>& arr);

    // function to generate a random number between a given range (inclusive)
    static int random_number_generator(int low, int high);


    //! SORTING FUNCTIONS
    // Basic Sorting Algorithms
    static void selection_sort(vector<int>& arr);

    static void insertion_sort(vector<int>& arr);

    static void bubble_sort(vector<int>& arr);

    // Advanced Sorting Algorithms
    static void merge_sorted_lists(vector<int>& arr, int left, int mid, int right);

    static void merge_sort(vector<int>& arr, int left, int right);

    // this merge function has time complexity O(n^2)
    static void inplace_merge_naive(vector<int>& arr, int left, int mid, int right);

    static void inplace_merge_shell(vector<int>& arr, int left, int mid, int right);

    //! NEEDS FIXING
    static void inplace_merge_optimum(vector<int>& arr, int left, int mid, int right);

    static void inplace_merge_sort(vector<int>& arr, int left, int right);

    static int partition(vector<int>& arr, int left, int right);

    static void quick_sort(vector<int>& arr, int left, int right);

    static int randomized_partition(vector<int>& arr, int left, int right);

    static void randomized_quick_sort(vector<int>& arr, int left, int right);

    // Linear Time Sorting Algorithms
    static void counting_sort(vector<int>& arr);

    static void bucket_sort(vector<int>& arr);

    static void radix_sort(vector<int>& arr);

    // Other Useful Sorting Algorithms
    static void shell_sort(vector<int>& arr);

};
