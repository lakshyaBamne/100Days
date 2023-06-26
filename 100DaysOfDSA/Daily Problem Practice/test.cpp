#include<iostream>
#include<vector>
#include<string>

using namespace std;

void reverse_subarray(vector<int>& arr, int left, int right){
    while(left < right){
        swap(arr[left++], arr[right--]);
    }
}

int main(){
    string num_str = "12345";

    

    return 0;
}