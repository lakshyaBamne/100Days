#include<iostream>
#include<vector>
#include<stack>

#include "DFS.h"

using namespace std;

int main(){
    stack<int> myStack;

    myStack.push(5);
    myStack.push(1);
    myStack.push(2);
    myStack.push(-9);
    myStack.push(0);

    DFS::show_stack(myStack);



    return 0;
}