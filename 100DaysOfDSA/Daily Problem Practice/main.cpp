/*
    main file to run and test the practice problems
*/
#include "striver_sde.h"
#include "misc.h"
#include "placement_sheet.h"

#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> arr = {1,5,1,3,6,7,8};

    // StriverSde::next_permutation(arr);

    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

