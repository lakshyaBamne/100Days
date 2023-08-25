#include<iostream>

#include "LinkedLists.h"

using namespace std;

/*
    Singly Linked Lists

    -> HEAD points to the first node in the Linked List
    -> every node contains some data and the pointer to the immediate node
    -> last node points to the NULL pointer
*/

void LinkedList::insert(int value){
    // create a new node and then insert it to the last node
    SLL_Node* new_node = new SLL_Node;

    new_node->data = value;
    new_node->next = NULL;

    if( HEAD==NULL ){
        HEAD = new_node;
        TAIL = new_node;
    }
    else{
        TAIL->next = new_node;
        TAIL = new_node;
    }

    cout << "---LOG--- added a new node ---" << endl;

}

void LinkedList::show_list(){
    SLL_Node* node = HEAD;

    cout << "HEAD : | ";
    while( node ){
        cout << node->data << " ";
        node = node->next;
    }
    cout << " | -> NULL" << endl;
}

//! STILL NEEDS CHANGES

//! To deal with cases when the element to be removed is at the HEAD itself
void LinkedList::remove_first(int value){
    SLL_Node* node = HEAD;
    SLL_Node* prev = HEAD;

    if( HEAD->data == value ){
        HEAD = HEAD->next;
        cout << "---LOG--- deleted first instance ---" << endl;
    }
    else{
        while( node ){
            if( node->data == value ){
                prev->next = node->next;
                delete node;

                cout << "---LOG--- deleted first instance ---" << endl;

                break;
            }
            else{
                prev = node;
                node = node->next;
            }
        }
    }
}

//! STILL NEEDS CHANGES
void LinkedList::remove_all(int value){
    SLL_Node* node = HEAD;
    SLL_Node* prev = HEAD;

    if( HEAD->data == value ){
        HEAD = HEAD->next;
    }
    else{
        while( node ){
            if( node->data == value ){
                prev->next = node->next;
                node = node->next;

                cout << "---LOG--- deleted one instance ---" << endl;
            }
            else{
                prev = node;
                node = node->next;
            }
        }
    }
}
