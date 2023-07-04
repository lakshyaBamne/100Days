#include<iostream>
#include<vector>
#include<utility>

#include "BinarySearch.h"

using namespace std;

int main(){
    vector<vector<int>> test = {
        {1,3},
        {6,9}
    };

    vector<int> test_new = {2,5};

    vector<vector<int>> output =  BinarySearchProblems::insert_interval(test, test_new);

    for(int i=0 ; i<output.size() ; i++){
        for(int j=0 ; j<output[0].size() ; j++){
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}