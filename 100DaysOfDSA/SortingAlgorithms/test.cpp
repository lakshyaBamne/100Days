#include<iostream>
#include<vector>

using namespace std;

void print_vector(vector<int>& arr){
    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int find_max(vector<int>& arr, int left, int right){
    int max = INT_MIN;

    for(int i=left ; i<=right ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

void merge_inplace_optimum(vector<int>& arr, int left, int mid, int right){
    // first find the maximum element in the array
    int max_more = find_max(arr, left, right);
    max_more++;

    cout << max_more << endl;

    // pointers to navigate and manipulate the subarray elements
    int left_pointer = left, right_pointer = mid+1, main_pointer = left;

    while( (left_pointer <= mid) && (right_pointer <= right) ){
        if( arr[left_pointer]%max_more <= arr[right_pointer]%max_more ){
            arr[main_pointer] = arr[main_pointer] + (arr[left_pointer]%max_more)*max_more;

            main_pointer++;
            left_pointer++;
        }
        else{
            arr[main_pointer] = arr[main_pointer] + (arr[right_pointer]%max_more)*max_more;

            main_pointer++;
            right_pointer++;
        }
    }

    while( main_pointer <= right ){
        arr[main_pointer] = arr[main_pointer] + arr[main_pointer]*max_more;
        main_pointer++;
    }

    // divide
    for(int i=left ; i<=right ; i++){
        arr[i] = arr[i] / max_more;
    }

}

void inplace_merge_sort(vector<int>& arr, int left, int right){
    int mid;

    if( left < right ){
        mid = (left + right) / 2;

        // divide step
        inplace_merge_sort(arr, left, mid);
        inplace_merge_sort(arr, mid+1, right);

        // conquer step
        merge_inplace_optimum(arr, left, mid, right);
    }
}

int main(){
    vector<int> arr = {1,2,3,1,4,8,2,2,1};

    cout << "Unmerged vector is : ";
    print_vector(arr);

    // it is required that the user correctly gives the left, mid and right pointers to the function
    inplace_merge_sort(arr, 0, arr.size()-1);

    cout << "Merged vector is : ";
    print_vector(arr);

    return 0;
}