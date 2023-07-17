#include<iostream>
#include<vector>
#include<unordered_map>

#include "MemoizationExamples.h"

using namespace std;

// Memoization in finding the n-th fibonacci number

long long int Memoization::recursive_fibonacci(int n, vector<long long int>& memo){
    /*
        This is the recursive call for a fibonacci number
    */

    if( memo[n] >= 0 ){
        return memo[n];
    }
    else{
        memo[n-2] = recursive_fibonacci(n-2, memo);
        memo[n-1] =  recursive_fibonacci(n-1, memo);

        memo[n] = memo[n-2] + memo[n-1];

        return memo[n];
    }


}

long long int Memoization::fibonacci(int n){
    /*
        Recursive (inductive) definition to find k-th fibonacci number

        -> fibonacci(0) = 0
        -> fibonacci(1) = 1
        -> fibonacci(k) = fibonacci(k-1) + fibonacci(k-2)

        * to visualise the problem which arises while using a recursive program
        * draw a tree structure to find the fibonacci and observe the wasteful computations
    */

    //! MEMO TABLE - stores the fibonacci number m<n during runtime of fibonacci(n)
    //* here we can use either a hash map or a vector (latter will be more space efficient)

    if( n < 0 ){
        return -1; // error as we have defined fibonacci for positive numbers
    }

    vector<long long int> memo(n+1,-1); // fibonacci(k) == memo[k] (if not negative)

    //! base cases
    memo[0] = 0; // fibonacci(0)
    memo[1] = 1; // fibonacci(1)

    return recursive_fibonacci(n, memo);    

}