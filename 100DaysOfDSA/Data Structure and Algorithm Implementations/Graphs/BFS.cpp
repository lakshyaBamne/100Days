#include<iostream>
#include<vector>
#include<queue>

#include "BFS.h"

using namespace std;

// Breadth First Search on an Adjacency List Representation
vector<int> BFS::BFS_AdjacencyList(int V, vector<int> adj_list[]){
    // We need to maintain a visited array to mark the visited vertices
    // initially all the vertices are marked not-visited 
    vector<bool> visited(V, false); // old syntax

    vector<int> BFS_order;

    // we can maintain a count variable to know when all the vertices have
    // been visited and then we can stop
    int count_processed = 0;

    // we also need to maintain a PROCESSING-QUEUE
    queue<int> processing;

    // we start by inserting the root element to the processing queue and marking it visited
    processing.push(0);
    visited[0] = true;

    BFS_order.push_back(0);

    int current_index;

    while( count_processed != V ){
        if( !processing.empty() ){
            current_index = processing.front();
            BFS_order.push_back(current_index);

            /*
                This is the area where custom processing will take place
                -> e.g., if we want to find an element in the graph
                the condition for comparison and stopping condition go here
            */

            processing.pop();
            count_processed++; // increase the number of nodes processed when popping
        }
        else{
            break;
        }

        // now get all the unvisited neighbours of current indes and push them to the 
        // processing queue
        for(auto i : adj_list[current_index]){
            if( !visited[i] ){
                processing.push(i);
                visited[i] = true;
            }
        }
    }

    return BFS_order;

}

// Breadth First Search on an Adjacency Matrix Representation
// Note: Adjacency matrix for a graph is always a square matrix
vector<int> BFS::BFS_AdjacencyMatrix(int V, vector<vector<int>> adj_mat){
    vector<int> BFS_order;

    // we have to maintain a visited array
    vector<bool> visited(adj_mat[0].size(), false); // old C++ syntax  

    queue<int> processing;

    int count_processed = 0;

    processing.push(0);
    visited[0] = true;

    int current_index;

    while( count_processed != adj_mat.size() ){
        // we have to make sure we dont pop from a queue that is empty
        if( !processing.empty() ){
            current_index = processing.front();
            BFS_order.push_back(current_index);

            processing.pop();
            count_processed++;
        }
        else{
            break;
        }
        
        // we stop when all the nodes are processed
        while( count_processed != adj_mat.size() ){
            for(auto i : adj_mat[current_index]){
                if( !visited[i] ){
                    processing.push(i);
                    visited[i] = true;
                }
            }

        }


    }

    return BFS_order;

}



