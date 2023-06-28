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
        {9,18}
    };

    // vector<vector<int>> intervals = {
    //     {1,4}
    // };

    for(int i=0 ; i<intervals.size() ; i++){
        for(int j=0 ; j<2 ; j++){
            cout << intervals[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    intervals = StriverSde::merge_intervals(intervals);

    for(int i=0 ; i<intervals.size() ; i++){
        for(int j=0 ; j<2 ; j++){
            cout << intervals[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    return 0;
}

