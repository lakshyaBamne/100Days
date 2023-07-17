#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class BFS{
public:

    /*
        Breadth First Search on a Matrix

        GeeksForGeeks -> https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
    */

    // Breadth First Search on an Adjacency List representation of a Graph
    static vector<int> BFS_AdjacencyList(int V, vector<int> adj_list[] );

    // Breadth First Search on an Adjacency Matrix representation of a Graph
    static vector<int> BFS_AdjacencyMatrix(int V, vector<vector<int>> adj_mat);

};