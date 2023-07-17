#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<utility>

using namespace std;

class GraphProblems{
public:
    static void show_stack(stack<int> myStack);
    static void show_queue(queue<pair<int,int>> myQueue);

    /*
        Ques-1 Find unit length of largest region of 1's

        GeeksForGeeks -> https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1
    */

    static bool is_inside(int row, int col, pair<int,int> point);

    static vector<pair<int,int>> find_neighbours(int row, int col, pair<int,int> point);
    static int area_connected_region(vector<vector<int>>& grid, vector<vector<bool>>& visited,pair<int,int> root);

    static pair<int,int> find_next_root(vector<vector<int>>& grid, vector<vector<bool>>& visited,pair<int,int> last_root);
    static int findMaxArea(vector<vector<int>>& grid);
};
