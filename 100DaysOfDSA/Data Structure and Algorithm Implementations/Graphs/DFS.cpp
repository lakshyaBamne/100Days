#include<iostream>
#include<vector>
#include<stack>

#include "DFS.h"

using namespace std;

// function to show the elements of a stack without changing it
void DFS::show_stack(stack<int> myStack){
    int stack_size = myStack.size();

    vector<int> temp(stack_size);

    cout << "Stack : <- | ";
    for(int i=0 ; i<stack_size ; i++){
        temp[i] = myStack.top();

        cout << temp[i] << " ";

        myStack.pop();
    }
    cout << " |" << endl;

    for(int i=temp.size()-1 ; i>=0 ; i--){
        myStack.push(temp[i]);
    }
}

// Depth First Search on an Adjacency List Representation

// This implementation gives a traversal where neighbours are pushed to
// stack from left to right of the adjacency list
vector<int> DFS::DFS_AdjacencyList(int V, vector<int> adj_list[]){
    // we need to maintain a visited array for nodes
    vector<bool> visited(V, false);

    vector<int> output;

    // we need to maintain a processing stack (to process elements and backtrack)
    stack<int> processing;

    // start by pushing the root node to the processing stack
    processing.push(0);

    int points_processed = 0;

    int to_process;

    while( points_processed < V ){
        to_process = processing.top();
        
        if( !processing.empty() ){
            if( !visited[to_process] ){
                output.push_back(to_process);
                visited[to_process] = true;

                processing.pop();
                points_processed++;
            }
            else{
                processing.pop();
            }
        }
        else{
            break;
        }

        // look at the non-visited adjacent neighbour of index to_process
        for(auto i : adj_list[to_process]){
            if( !visited[i] ){
                processing.push(i);
            }
        }


    }

    return output;

}
