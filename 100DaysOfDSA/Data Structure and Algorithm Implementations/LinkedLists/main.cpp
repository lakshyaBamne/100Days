#include<iostream>

#include "LinkedLists.h"

using namespace std;

int main(){
    LinkedList myList;

    myList.insert(-4);
    myList.insert(10);
    myList.insert(-6);
    myList.insert(1);
    myList.insert(-4);

    myList.show_list();

    // myList.remove_first(-4);
    myList.remove_all(-4);

    myList.show_list();

    return 0;
}