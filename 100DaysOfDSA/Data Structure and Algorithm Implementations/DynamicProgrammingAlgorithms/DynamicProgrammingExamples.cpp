#include<iostream>
#include<vector>
#include<unordered_map>

#include "DynamicProgrammingExamples.h"

using namespace std;

// Example-1 : Factorial of a positive integer
long long int DynamicProgramming::factorial(int n){
    if( n <= 1 ){
        return 1;
    }

    long long int prev = 1;

    for(int i=0 ; i<n ; i++){
        prev = (i+1)*prev;
    }

    return prev;
}
