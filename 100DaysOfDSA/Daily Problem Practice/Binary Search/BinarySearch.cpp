#include "BinarySearch.h"

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

// Ques-1 GIF of Square root of x
int BinarySearchProblems::sqrt(int x){
    /*
        NOTE:-

        APPROACH:-
        Binary Search approach to find the Square root of a number
        -> can be extended to find any nth root of the number
    */
    if(x < 3){
        return 1;
    }

    int left_limit = 1;
    int right_limit = (x/2)+1;

    long long int mid;

    while( left_limit < right_limit-1 ){
        mid = (left_limit + right_limit) / 2;

        if( mid*mid <= x ){
            left_limit = mid;
        }  
        else{
            right_limit = mid;
        }
    }

    return left_limit;
}
