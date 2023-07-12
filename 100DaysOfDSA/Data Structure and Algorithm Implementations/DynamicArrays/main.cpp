#include<iostream>

#include "DynamicArray.h"

using namespace std;

int main(){
    DynamicArray arr_1;
    DynamicArray arr_2(10);
    DynamicArray arr_3(5,-10);

    arr_3.insert(1,3);

    arr_3.print_array();


    return 0;
}
