#pragma once

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Memoization{
public:

    /*
        Example-1 : nth Fibonacci number
    */
    static long long int recursive_fibonacci(int n, vector<long long int>& memo); // recursive function
    static long long int fibonacci(int n); // main function

};


