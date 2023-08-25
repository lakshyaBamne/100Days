#pragma once

#include<iostream>

using namespace std;

/*
    Node for a singly linked list
*/
class SLL_Node{
public:
    int data; // data stored in the node
    SLL_Node* next; // pointer to the next node
};

/*
    Singly Linked List
*/
class LinkedList{
public: 
    // pointer to the first node of the list
    SLL_Node* HEAD = NULL;
    SLL_Node* TAIL = HEAD;

    int LIST_SIZE = 0;

    // method to insert a node to the linked list
    void insert(int value);

    // method to show the contents of a linked list
    void show_list();
    
    // method to remove the first instance of an element from the linked list
    void remove_first(int value);

    // method to remove all instances of an element from the linked list
    void remove_all(int value);

};

