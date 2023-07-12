#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>

#include "Arrays.h"

using namespace std;

int main(){
    srand(time(0));

    vector<int> nums = {3,2,3,1,2,4,5,5,6};

    cout << ArrayProblems::order_statistics(nums, 4) << endl;

    return 0;
}