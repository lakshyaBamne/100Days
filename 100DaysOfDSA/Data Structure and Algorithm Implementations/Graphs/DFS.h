#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class DFS{
public:

    /*
        Depth First Search on a Graph (Adjacency List and Matrix)

        GeeksForGeeks -> https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
    */

    // function to show the contents of a stack without changing it
    static void show_stack(stack<int> myStack);

    // Breadth First Search on an Adjacency List representation of a Graph
    static vector<int> DFS_AdjacencyList(int V, vector<int> adj_list[] );

};