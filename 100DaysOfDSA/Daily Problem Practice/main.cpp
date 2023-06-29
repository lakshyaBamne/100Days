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
    vector<vector<int>> intervals = {
        {1,3},
        {2,6},
        {8,10},
        {15,18},
        {16,20}
    };

    for(auto it : intervals){
        for(auto i : it){
            cout << i << " ";
        }
        cout << "\n";
    }

    auto output = StriverSde::merge_intervals(intervals);

    for(auto it : output){
        for(auto i : it){
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

