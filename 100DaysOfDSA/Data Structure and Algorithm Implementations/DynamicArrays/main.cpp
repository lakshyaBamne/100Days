#include<iostream>

#include "DynamicArray.h"

using namespace std;

int main(){
    DynamicArray arr_1;
    DynamicArray arr_2(10);
    DynamicArray arr_3(5,-10);

    cout << arr_1[0] << endl;
    cout << arr_2[5] << endl; 
    cout << arr_3[4] << endl;

    return 0;
}
