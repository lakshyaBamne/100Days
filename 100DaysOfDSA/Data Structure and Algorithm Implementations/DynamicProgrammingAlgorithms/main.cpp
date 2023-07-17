#include<iostream>
#include<vector>
#include<unordered_map>

#include "MemoizationExamples.h"
#include "DynamicProgrammingExamples.h"

using namespace std;

int main(){
    int k = 20;

    for(int i=0 ; i<k ; i++){
        cout << "-----------------------------------" << endl;
        cout << "fibonacci(" << i+1 << ") : " << Memoization::fibonacci(i+1) << endl;
        cout << "factorial(" << i+1 << ") : " << DynamicProgramming::factorial(i+1) << endl;
    }

    return 0;
}